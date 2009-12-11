#pragma once
#if !defined(TRACKMANAGERFACTORY_H)
#define TRACKMANAGERFACTORY_H

#include "TrackManager.h"

class CTrackManagerFactory{

	private:
		CTrackManagerFactory(void);
		~CTrackManagerFactory(void);
	public:
		static ITrackManager* createInstance( void );

};//class CTrackManagerFactory

#endif //TRACKMANAGERFACTORY_H