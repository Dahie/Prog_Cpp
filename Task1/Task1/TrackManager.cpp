#include "StdAfx.h"
#include "TrackManager.h"

CTrackManager::CTrackManager( void ){
}

CTrackManager::~CTrackManager( void ){
}

int CTrackManager::addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData ){
	return 0;
}
bool CTrackManager::removeTrack( int pIndex ){
	return false;
}
int CTrackManager::trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID ){
	return 0;
}
bool CTrackManager::trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack ){
	return false;
}
void CTrackManager::trackSearchStop( TSearchID pID ){

}
