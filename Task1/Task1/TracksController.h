#pragma once
#if !defined(TRACKSCONTROLLER_H)
#define TRACKSCONTROLLER_H

#include "MP3ReaderFactory.h"
#include "Tracks.h"
#include "SortedTitles.h"

enum Response{
	NO_MP3_FILE, NOT_READ, OK, ALREADY_OPENED
};

class CTracksController
{
	private:
		MP3::CTracks* tracks;
		MP3::CSortedTitles* sortedTitles;
		MP3::IMP3Reader* mp3Reader;

	public:
		CTracksController( void );
		~CTracksController( void );

		Response addFile( const std::string& filePath );
		MP3::CMP3Audio* getFile( const std::string& name );
		MP3::CSortedTitles* getAllTitles( void );
		void removeFile( const std::string& name );
		void removeAllFiles( void );
	
};

#endif //TRACKSCONTROLLER_H
