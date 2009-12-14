#include "StdAfx.h"
#include "TrackSearches.h"

CTrackSearches::CTrackSearches(void)
{
}

CTrackSearches::~CTrackSearches(void)
{
}

void CTrackSearches::addTrackSearch( const TSearchID id, CSortedTrackInfos* trackInfos ){
	searches[id]=trackInfos;
}

CSortedTrackInfos* CTrackSearches::getTrackSearch( const TSearchID id ){
	if(!searches.empty()){
		tracksearch_it iter = searches.find(id);
		return (iter != searches.end() ? iter->second : NULL);
	}
	return NULL;
}

void CTrackSearches::removeTrackSearch( const TSearchID id ){
	if(!searches.empty()){
		tracksearch_it iter = searches.find(id);
		if(iter != searches.end()){
			delete iter->second;
			searches.erase(id);
		}
	}
}

//delete all searches in container
void CTrackSearches::clearTrackSearches( void ){
	if(!searches.empty()){
		tracksearch_it	iter;
		for ( iter = searches.begin(); iter != searches.end(); ++iter ){
			delete iter->second;
		}
		searches.clear();
	}
}

//is search in container
bool CTrackSearches::isInCollection( const std::string& searchterm ){
	bool flag = false;

	if(!searches.empty()){
		tracksearch_it iter;
		for ( iter = searches.begin(); iter != searches.end(); ++iter ) {
			/*std::string trackName((*(iter->second)).getFileName());
			if(trackName == track->getFileName()){
				flag = true;
			}*/
		}
	}
	return flag;
}

//is container empty
bool CTrackSearches::isEmpty( void ) const{
	return searches.empty();
}

//size of searches collection
const CTrackSearches::tracksearch_sz_type CTrackSearches::getSizeOfTrackSearches( void ) const{
	return searches.size();
}

//begin-iterators and end-iterators
CTrackSearches::tracksearch_it CTrackSearches::getBeginIterator( void ){
	return searches.begin();
}

CTrackSearches::tracksearch_it CTrackSearches::getEndIterator( void ){
	return searches.end();
}

CTrackSearches::tracksearch_const_it CTrackSearches::getBeginIterator( void) const{
	return searches.begin();
}

CTrackSearches::tracksearch_const_it CTrackSearches::getEndIterator( void ) const{
	return searches.end();
}