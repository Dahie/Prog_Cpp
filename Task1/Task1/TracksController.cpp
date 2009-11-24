#include "StdAfx.h"
#include "TracksController.h"


CTracksController::CTracksController( void ):tracks( new MP3::CTracks() ), 
  sortedTitles( new MP3::CSortedTitles() ), 
  mp3Reader( MP3::CMP3ReaderFactory::createInstance() ),
  indexer ( new Search::Indexer() )
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
	delete this->sortedTitles;
  delete this->indexer;
	this->tracks->clearTracks();
	delete this->tracks;
}

enum Response CTracksController::addFile( const std::string& filePath ){

	//check if file is a mp3
	if(!this->mp3Reader->isMP3File(filePath)){
		return NO_MP3_FILE;
	}

	//read ID3 tags and create mp3 object
	MP3::CMP3Audio* mp3audio = this->mp3Reader->readMP3Data(filePath);
	if(!mp3audio){
		return NOT_READ;
	}

	if(!this->tracks->isInCollection(mp3audio)) { //check if mp3 with this filename exists

		//create name for title list
		std::string name = mp3audio->getTitle();

		//if mp3 with same title exists
		if(this->tracks->isTitleInCollection(mp3audio)){
			//create new name for track with current counter at the end
			createStdString(name, this->tracks->getTitleCount());	
		}

		//add mp3 in tracks collection and the title in sorted titlelist
		this->tracks->addTrack(name, mp3audio);
		this->sortedTitles->insertTitle(name);	

	}else{ return ALREADY_OPENED; }

  return OK;
}

MP3::CMP3Audio* CTracksController::getFile( const std::string& name ){
	return this->tracks->getTrack(name);
}

MP3::CSortedTitles* CTracksController::getAllTitles( void ){
	return this->sortedTitles;
}

MP3::CSortedTitles* CTracksController::find( const std::string& searchword ) const{
	return this->indexer->findAll(searchword);
}

void CTracksController::removeFile( const std::string& name ){
	
	//store information needed from mp3 which should be removed
	MP3::CMP3Audio* mp3audio = this->tracks->getTrack(name);
	bool flag = this->tracks->isTitleInCollection(mp3audio);
	const std::string title = mp3audio->getTitle();
	
	//remove track in both collections
	this->tracks->removeTrack(name);
	this->sortedTitles->removeTitle(name);

	//if tracks with same title rename them if necessary
	if(flag){	
		this->renameUniqueTitles( name, title );
	}		
}

void CTracksController::removeAllFiles( void ){
	//remove all tracks in both collections
	this->tracks->clearTracks();
	this->sortedTitles->clearTitles();
}

void CTracksController::renameUniqueTitles( const std::string& name, const std::string& title ){

		std::string compName = name;

		MP3::CTracks* help = new MP3::CTracks();
		MP3::CSortedTitles* helpTitles = new MP3::CSortedTitles();

		MP3::CTracks::mp3_it iter = this->tracks->getBeginIterator();
		for(iter; iter != this->tracks->getEndIterator(); ++iter){
		
			if( title == iter->second->getTitle()){
				
				if(compName < iter->first){
				
					help->addTrack(compName, iter->second);
					compName = iter->first;
					helpTitles->addTitle(compName);	
				}
			}
		}

		//delete all tracks with name from helpTitles
		MP3::CSortedTitles::iterator it = helpTitles->getBeginIterator();
		for(it; it != helpTitles->getEndIterator(); ++it){
			this->tracks->eraseTrack(it->sTitleName);
			this->sortedTitles->removeTitle(it->sTitleName);
		}

		//add tracks from help in both collection
		iter = help->getBeginIterator();
		for(iter; iter != help->getEndIterator(); ++iter){
			this->tracks->addTrack(iter->first, iter->second);
			this->sortedTitles->insertTitle(iter->first);
		}

		delete helpTitles;
		delete help;
}

