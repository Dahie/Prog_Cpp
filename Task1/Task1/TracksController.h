#pragma once
#if !defined(TRACKSCONTROLLER_H)
#define TRACKSCONTROLLER_H

#include "MP3ReaderFactory.h"
#include "Tracks.h"
#include "SortedTitles.h"
#include "Utils.h"
#include "Indexer.h"

enum Response{
	NO_MP3_FILE, NOT_READ, OK, ALREADY_OPENED
};

class CTracksController
{
	private:
		MP3::CTracks* tracks;
		MP3::CSortedTitles* sortedTitles;
		MP3::IMP3Reader* mp3Reader;
    Search::Indexer* indexer;

	public:
		CTracksController( void );
		~CTracksController( void );

		Response addFile( const std::string& filePath );
		MP3::CMP3Audio* getFile( const std::string& name );
		MP3::CSortedTitles* getAllTitles( void );
		MP3::CSortedTitles* findTitles( const std::string& searchword ) const;
		void removeFile( const std::string& name );
		void removeAllFiles( void );
		void renameUniqueTitles( const std::string& name, const std::string& title );	
		unsigned int getIndexLength() const;
		unsigned int getIndexCapacity() const;

}; //class CTracksController

#endif //TRACKSCONTROLLER_H
