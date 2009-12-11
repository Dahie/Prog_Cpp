#pragma once
#if !defined(CTRACKMANAGER_H)
#define CTRACKMANAGER_H

#include "ITrackManager.h"

class CTrackManager : public ITrackManager{
	public:
		CTrackManager(void);
		~CTrackManager(void);

		int addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData );
		bool removeTrack( int pIndex );

		int trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID );
		bool trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack );
		void trackSearchStop( TSearchID pID );

};//class CTrackManager

#endif //CTRACKMANAGER_H
