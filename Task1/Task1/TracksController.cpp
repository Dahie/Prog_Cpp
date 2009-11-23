#include "StdAfx.h"
#include "TracksController.h"
#include <sstream>

CTracksController::CTracksController( void ):tracks( new MP3::CTracks() ), 
sortedTitles( new MP3::CSortedTitles() ), mp3Reader( MP3::CMP3ReaderFactory::createInstance() )
{
	if( (!tracks) || (!sortedTitles) || (!mp3Reader) ){ 
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

			//create new name for title list with current counter at the end
			std::stringstream ss;
			ss << " (" << this->tracks->getTitleCount() << ") ";
			name += ss.str();

			//second check
			int count = 2;
			while(NULL != this->tracks->getTrack(name)){
				
				std::string newName = mp3audio->getTitle();
				
				if(NULL != this->tracks->getTrack(newName)){
					std::stringstream ss1;
					ss1 << " (" << count << ") ";
					newName += ss1.str();
				}
				name = newName;
				++count;
			}
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

void CTracksController::removeFile( const std::string& name ){
	//remove track in both collections
	this->sortedTitles->removeTitle(name);
	this->tracks->removeTrack(name);
}

void CTracksController::removeAllFiles( void ){
	//remove all tracks in both collections
	this->tracks->clearTracks();
	this->sortedTitles->clearTitles();
}

