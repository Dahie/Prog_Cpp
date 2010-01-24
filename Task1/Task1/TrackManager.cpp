#include "StdAfx.h"
#include "TrackManager.h"
#include "LockClasses.h"

CTrackManager::CTrackManager( void ): controller( new CTracksController() ), 
  lock_add_track( new CReadWriteLock() ), indexCount(0), indexSearch(0)
{
	if( (!controller) ){ 
		System::Windows::Forms::MessageBox::Show("\nERROR: No memory access. Some components failed to load.\n\n"+
			"\n              ----- MP3Tagger will be closed. -----\n\n\n         Please try to restart the application later!!!\n\n\n","MP3 Tagger",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		exit(0);
	}
}

CTrackManager::~CTrackManager( void ){
	delete this->controller;
}

int CTrackManager::addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData ){
	
  lock_add_track->lockReader();
  lock_add_track->lockWriter();
  

	//pass file to controller, read ID3 tags and create mp3 object, store it in collection
	std::string name = "";
	Response response = this->controller->addFile(pFileName, name);
  unsigned int return_value = 0;
	switch(response){
		case NO_MP3_FILE: 
			return_value = -2;
      break;
		case NOT_READ: 
			return_value = -3;
      break;
		case OK:{

			//copy mp3 data into CTrackInfo object
			MP3::CMP3Audio* mp3audio = this->controller->getFile(name);
			pTrackData.mAlbum = mp3audio->getAlbum();
			pTrackData.mInterpret = mp3audio->getArtist();
			pTrackData.mTitle = mp3audio->getTitle();

			//add title to mapping container and store index in track info object
			this->mapping[this->indexCount] = pTrackData.mTitle;			
			pTrackData.mIndex = this->indexCount;
			++this->indexCount;
			
			return_value = pTrackData.mIndex;
      break;
		}
		case ALREADY_OPENED:
			return_value = INVALID_INDEX;
      break;
    default:
      return_value = INVALID_INDEX;
      break;
	}//end of switch

  lock_add_track->unlockReader();
  lock_add_track->unlockWriter();

	return return_value;
}

bool CTrackManager::removeTrack( int pIndex ){

	bool flag = true;

	if(!this->mapping.empty()){
		std::map<unsigned int, std::string>::iterator iter = this->mapping.find(pIndex);
		if( iter != this->mapping.end() ){
			if(this->mapping.size() <= 1){
				this->controller->removeAllFiles();
			}else{
				this->controller->removeFile(iter->second);
			}
			this->mapping.erase(pIndex);
			flag = true;
		}else{
			flag = false;
		}
	} 
	if(this->mapping.empty()) this->indexCount=0;
	return flag;
}

int CTrackManager::trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID ){

	//fill indexer and get search result as title list
	MP3::CSortedTitles* foundTitles = this->controller->findTitles(pTitleBeginn);
	
	///set current iterator to begin
	if(foundTitles != 0){
		foundTitles->setCurrentIterator(foundTitles->getBeginIterator());
	}
	
	//get and set searchID
	pID = this->indexSearch;
	++this->indexSearch;
	this->searches[pID] = foundTitles;

	if(foundTitles == 0){
		this->searches[pID] = new MP3::CSortedTitles();
		return 0;
	}
	return static_cast<int>(foundTitles->getSizeOfSortedTitles());
}

bool CTrackManager::trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack ){
	
	bool flag = false;
	MP3::CSortedTitles* foundTitles = 0;

	std::map<unsigned int, MP3::CSortedTitles*>::iterator it = this->searches.find(pID);
	if( it != this->searches.end() ){
		foundTitles = it->second;
	}

	//get current iterator of title list
	MP3::CSortedTitles::iterator iter = foundTitles->getCurrentIterator();
	
	if(foundTitles != 0 && (iter != foundTitles->getEndIterator())){
	
		//get and store data for track info object
		pNextTrack.mTitle = (*iter).sTitleName;
		MP3::CMP3Audio* mp3audio = this->controller->getFile(pNextTrack.mTitle);
		pNextTrack.mAlbum = mp3audio->getAlbum();
		pNextTrack.mInterpret = mp3audio->getArtist();

		//set current iterator to next element in list
		foundTitles->setCurrentIterator(++iter);

		if(iter != foundTitles->getEndIterator()){
			flag = true;
		}
	}
	return flag; //true if iterator points to a track in list
}

void CTrackManager::trackSearchStop( TSearchID pID ){
	//this->searches.find(pID)->second->clearTitles();
	this->searches.erase(pID);
	if(this->searches.empty()) this->indexSearch = 0;
}
