#include "StdAfx.h"
#include "TrackManagerFactory.h"

CTrackManagerFactory::CTrackManagerFactory(void)
{
}

CTrackManagerFactory::~CTrackManagerFactory(void)
{
}

ITrackManager* CTrackManagerFactory::createInstance( void ){
	return new CTrackManager();
}
