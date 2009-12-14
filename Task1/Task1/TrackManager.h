#pragma once
#if !defined(CTRACKMANAGER_H)
#define CTRACKMANAGER_H

#include "ITrackManager.h"
#include "TracksController.h"
#include <map>
#include <vector>

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
		index_sz_type indexCount;
		index_sz_type indexSearch;
		std::map<index_sz_type, std::string> mapping;
		std::map<index_sz_type, MP3::CSortedTitles*> searches;

};//class CTrackManager

#endif //CTRACKMANAGER_H
