#include "StdAfx.h"
#include "TrackManager.h"

CTrackManager::CTrackManager( void ): controller( new CTracksController() ), indexCount(0)
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
	
	//pass file to controller, read ID3 tags and create mp3 object, store it in collection
	std::string name = "";
	Response response = this->controller->addFile(pFileName, name);

	switch(response){

		case NO_MP3_FILE:{ 
			return -2;
		}
		case NOT_READ:{ 
			return -3;
		}
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
			
			return pTrackData.mIndex;
		}
		case ALREADY_OPENED:{
			return INVALID_INDEX;
		}
	}//end of switch

	return INVALID_INDEX;
}

bool CTrackManager::removeTrack( int pIndex ){

	bool flag = true;

	if(!this->mapping.empty()){
		std::map<unsigned int, std::string>::iterator iter = this->mapping.find(pIndex);
		if( iter != this->mapping.end() ){
			this->controller->removeFile(iter->second);
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

	MP3::CSortedTitles* foundTitles = this->controller->findTitles(pTitleBeginn);
	pID = static_cast<int>(this->searches.size());
	this->searches.push_back(foundTitles);
	
	if(foundTitles == 0)return 0;
	return static_cast<int>(foundTitles->getSizeOfSortedTitles());
}
bool CTrackManager::trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack ){
	
	this->searches.at(pID);
	return false; //true if next track is in list
}
void CTrackManager::trackSearchStop( TSearchID pID ){

}
