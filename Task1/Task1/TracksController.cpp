#include "StdAfx.h"
#include "TracksController.h"

CTracksController::CTracksController(void)
{

	tracks = new MP3::CTracks();
	sortedTracks = new MP3::CSortedTracks();
}

CTracksController::~CTracksController(void)
{
}

Response CTracksController::addFile(std::string& filePath){

	MP3::IMP3Reader* mp3Reader = new CID3Reader();
	
	//check if file is a mp3
	if(!mp3Reader->isMP3File(filePath.c_str())){
		return Response::NO_MP3_FILE;
	}

	//read ID3 tags and create mp3 object
	MP3::CMP3Audio* mp3audio = mp3Reader->read(filePath);
	if(!mp3audio){
		return Response::NOT_READ;
	}

	if(!this->tracks->isInCollection(mp3audio)) { //check if mp3 with this filename exists

		//if mp3 with same title exists
		if(this->tracks->isTitleInCollection(mp3audio)){

			name = mp3audio->getTitle();
				
			//create new name for title list with current counter at the end
			String^ iNumOfTitle = " (" + this->tracks->getTitleCount().ToString()+ ")";
			std::string num ="";
			MarshalString(iNumOfTitle, num);
			name += num;

			//add mp3 in tracks collection and the title in sorted titlelist
			this->tracks->addTrack(mp3audio, name);
			this->sortedTracks->addTrack(name);

		}else{
			//create name for title list
			name = mp3audio->getTitle();
			//add mp3 in tracks collection and the title in sorted titlelist
			this->tracks->addTrack(mp3audio, name);
			this->sortedTracks->addTrack(name);
		}

		//sort title list
		this->sortedTracks->sortTracks();

	}else{ return Response::ALREADY_OPENED; }

	return Response::OK;
}
