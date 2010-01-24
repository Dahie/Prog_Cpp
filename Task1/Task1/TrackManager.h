#pragma once
#if !defined(CTRACKMANAGER_H)
#define CTRACKMANAGER_H

#include "ITrackManager.h"
#include "TracksController.h"
#include "LockClasses.h"
#include <map>

class CTrackManager : public ITrackManager{
	
	public:
		CTrackManager(void);
		~CTrackManager(void);

		typedef unsigned int index_sz_type;

		int addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData );
		bool removeTrack( int pIndex );

		int trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID );
		bool trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack );
		void trackSearchStop( TSearchID pID );

	private:
		CTracksController* controller;
		index_sz_type indexCount; // number of opened files
		index_sz_type indexSearch; // number of saved searches
		std::map<index_sz_type, std::string> mapping; // maps unique titel to unique id
		std::map<index_sz_type, MP3::CSortedTitles*> searches; // saves searches

    // Read/write locks
    CReadWriteLock* lock_add_track;

};//class CTrackManager

#endif //CTRACKMANAGER_H
