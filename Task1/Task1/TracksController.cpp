#include "StdAfx.h"
#include "TracksController.h"
#include <algorithm>


CTracksController::CTracksController( void ): 
  tracks( new MP3::CTracks() ), 
  sortedTitles( new MP3::CSortedTitles() ), 
  mp3Reader( MP3::CMP3ReaderFactory::createInstance() ), 
  indexer ( new Search::Indexer()),
  lock_indexer(new CReadWriteLock()),
  lock_mp3reader(new CReadWriteLock()),
  lock_sorted_titles(new CReadWriteLock()),
  lock_tracks(new CReadWriteLock())
{
	if( (!tracks) || (!sortedTitles) || (!mp3Reader) || (!indexer)  ){ 
		System::Windows::Forms::MessageBox::Show("\nERROR: No memory access. Some components failed to load.\n\n"+
			"\n              ----- MP3Tagger will be closed. -----\n\n\n         Please try to restart the application later!!!\n\n\n","MP3 Tagger",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		exit(0);
	}
}

CTracksController::~CTracksController( void )
{
	delete this->mp3Reader;
	delete this->indexer;
	delete this->sortedTitles;
	this->tracks->clearTracks();
	delete this->tracks;
}

enum Response CTracksController::addFile( const std::string& filePath, std::string& titleName ){
	
	//check if file is a mp3
  this->lock_mp3reader->lockReader();
	if(!this->mp3Reader->isMP3File(filePath)){
		return NO_MP3_FILE;
	}
  this->lock_mp3reader->unlockReader();

	//read ID3 tags and create mp3 object
  this->lock_mp3reader->lockWriter();
	MP3::CMP3Audio* mp3audio = this->mp3Reader->readMP3Data(filePath);
	if(!mp3audio){
		return NOT_READ;
	}
  this->lock_mp3reader->unlockWriter();

  this->lock_tracks->lockReader();
	if(!this->tracks->isTitleInCollection(mp3audio)) { //check if with same title exists
    this->lock_tracks->unlockReader();
		//add mp3 in tracks collection and the title in sorted titlelist
    this->lock_tracks->lockWriter();
		this->tracks->addTrack(mp3audio->getTitle(), mp3audio);
    this->lock_tracks->unlockWriter();
		//this->sortedTitles->insertTitle(name);

    this->lock_sorted_titles->lockReader();
		this->sortedTitles->addTitle(mp3audio->getTitle());
    this->lock_sorted_titles->unlockReader();

		//add title and words of title into indexer
    this->lock_indexer->lockWriter();
		this->indexer->insert(mp3audio->getTitle());
    this->lock_indexer->unlockWriter();

		titleName = mp3audio->getTitle();

	}else{ 
    this->lock_tracks->unlockReader();
    return ALREADY_OPENED; }

  return OK;
}

enum Response CTracksController::addFile( const std::string& filePath ){

	//check if file is a mp3
  this->lock_mp3reader->lockReader();
	if(!this->mp3Reader->isMP3File(filePath)){
		return NO_MP3_FILE;
	}
  this->lock_mp3reader->lockReader();

	//read ID3 tags and create mp3 object
  this->lock_mp3reader->lockWriter();	
	MP3::CMP3Audio* mp3audio = this->mp3Reader->readMP3Data(filePath);
	if(!mp3audio){
		return NOT_READ;
	}
  this->lock_mp3reader->unlockWriter();

  this->lock_tracks->lockReader();
	if(!this->tracks->isInCollection(mp3audio)) { //check if mp3 with this filename exists
    this->lock_tracks->unlockReader();
		//create name for title list
		std::string name = mp3audio->getTitle();

		//if mp3 with same title exists
    this->lock_tracks->lockReader();
		if(this->tracks->isTitleInCollection(mp3audio)){
			//create new name for track with current counter at the end
			createStdString(name, this->tracks->getTitleCount());	
		}
    this->lock_tracks->unlockReader();

		//add mp3 in tracks collection and the title in sorted titlelist
    this->lock_tracks->lockWriter();
		this->tracks->addTrack(name, mp3audio);
    this->lock_tracks->unlockWriter();

    this->lock_sorted_titles->lockWriter();
		//this->sortedTitles->insertTitle(name);
		this->sortedTitles->addTitle(name);
    this->lock_sorted_titles->unlockWriter();

		//add title and words of title into indexer
    this->lock_indexer->lockWriter();
		this->indexer->insert(name);
    this->lock_indexer->unlockWriter();
	}else{ 
    this->lock_tracks->unlockReader();
    return ALREADY_OPENED; }

  return OK;
}

MP3::CMP3Audio* CTracksController::getFile( const std::string& name ){
  this->lock_tracks->lockReader();
  MP3::CMP3Audio* audio = this->tracks->getTrack(name);
  this->lock_tracks->unlockReader();
	return audio;
}

MP3::CSortedTitles* CTracksController::getAllTitles( void ){
  this->lock_sorted_titles->lockReader();
  MP3::CSortedTitles* titles = this->sortedTitles;
  this->lock_sorted_titles->unlockReader();
  return titles;
}

MP3::CSortedTitles* CTracksController::findTitles( const std::string& searchword ) const {
  std::string word_lowercase = searchword;
  std::transform(word_lowercase.begin(), word_lowercase.end(), word_lowercase.begin(), tolower);

  this->lock_indexer->lockReader();
  MP3::CSortedTitles* result = this->indexer->findAll(word_lowercase);
  this->lock_indexer->unlockReader();
	return result;
}

unsigned int CTracksController::getIndexLength() const {
  this->lock_indexer->lockReader();
  unsigned int length = this->indexer->get_length();
  this->lock_indexer->unlockReader();
	return length;
}

unsigned int CTracksController::getIndexCapacity() const {
  this->lock_indexer->lockReader();
  unsigned int capacity = this->indexer->get_capacity();
  this->lock_indexer->unlockReader();
  return capacity;
}

void CTracksController::outputListElements(){
  // what does it output if the return value is void?
	return this->indexer->outputListElements();
}

void CTracksController::removeFile( const std::string& name ){
	
	//store information needed from mp3 which should be removed
	MP3::CMP3Audio* mp3audio = this->tracks->getTrack(name);
  this->lock_tracks->lockReader();
	this->tracks->isTitleInCollection(mp3audio);
	bool flag = this->tracks->getTitleCount() > 2;
	const std::string title = mp3audio->getTitle();
	this->lock_tracks->unlockReader();

	//remove track in both collections
  this->lock_tracks->lockWriter();
	this->tracks->removeTrack(name);
  this->lock_tracks->unlockWriter();
  this->lock_sorted_titles->lockWriter();
	this->sortedTitles->removeTitle(name);
  this->lock_sorted_titles->unlockWriter();


	//remove title and all entries to words from indexer
  this->lock_indexer->lockWriter();
	this->indexer->remove(name);
  this->lock_indexer->unlockWriter();

	//if tracks with same title, rename them if necessary TODO: update indexer
	if(flag){	
		this->renameUniqueTitles( name, title );
	}
}

void CTracksController::removeAllFiles( void ){
	//remove all tracks in both collections
  this->lock_tracks->lockWriter();
	this->tracks->clearTracks();
  this->lock_tracks->unlockWriter();

  this->lock_sorted_titles->lockWriter();
	this->sortedTitles->clearTitles();
  this->lock_sorted_titles->unlockWriter();
  
  //remove all indizes in indexer
  this->lock_indexer->lockWriter();
	this->indexer->clearIndices();
  this->lock_indexer->unlockWriter();
}

void CTracksController::renameUniqueTitles( const std::string& name, const std::string& title ){

		std::string compName = name;
		MP3::CTracks* help = new MP3::CTracks();
		MP3::CSortedTitles* helpTitles = new MP3::CSortedTitles();

    this->lock_tracks->lockReader();
		MP3::CTracks::mp3_it iter = this->tracks->getBeginIterator();
		for(iter; iter != this->tracks->getEndIterator(); ++iter){
			if( title == iter->second->getTitle() && compName < iter->first){
				help->addTrack(compName, iter->second);
				compName = iter->first;
				helpTitles->addTitle(compName);
			}
		}
    this->lock_tracks->unlockReader();

		//delete all tracks with name from helpTitles
		MP3::CSortedTitles::iterator it = helpTitles->getBeginIterator();
		for(it; it != helpTitles->getEndIterator(); ++it){
      this->lock_tracks->lockWriter();
			this->tracks->eraseTrack(it->sTitleName);
			this->lock_tracks->unlockWriter();
      this->lock_sorted_titles->lockWriter();
      this->sortedTitles->removeTitle(it->sTitleName);
			this->lock_sorted_titles->unlockWriter();
      this->lock_indexer->lockWriter();
      this->indexer->remove(it->sTitleName);
		  this->lock_indexer->unlockWriter();
    }

		//add tracks from help in both collection
		iter = help->getBeginIterator();
		for(iter; iter != help->getEndIterator(); ++iter){
      this->lock_tracks->lockWriter();
			this->tracks->addTrack(iter->first, iter->second);
			this->lock_tracks->unlockWriter();
      this->lock_sorted_titles->lockWriter();
      this->sortedTitles->insertTitle(iter->first);
			this->lock_sorted_titles->unlockWriter();
      this->lock_indexer->lockWriter();
      this->indexer->insert(iter->first);
		  this->lock_indexer->unlockWriter();
    }

		delete helpTitles;
		delete help;
}