#include "StdAfx.h"
#include "Tracks.h"

using namespace MP3;

CTracks::CTracks(void): iTitleCount(0)
{
}

CTracks::~CTracks(void)
{
}

//add mp3 at the end of container
void CTracks::addTrack( const std::string& name, MP3::CMP3Audio* track ) {
		tracks[name]=track;
}

//get a mp3
MP3::CMP3Audio* CTracks::getTrack( const std::string& name ) {
	if(!tracks.empty()){
		mp3_it iter = tracks.find(name);
		return (iter != tracks.end() ? iter->second : NULL);
	}
	return NULL;
}

//remove a mp3 in container
void CTracks::removeTrack( const std::string& name ){
	if(!tracks.empty()){
		mp3_it iter = tracks.find(name);
		if(iter != tracks.end()){
			delete iter->second;
			tracks.erase(name);
		}
	}
}

//remove item in container but save oject
void CTracks::eraseTrack( const std::string& name ){
	if(!tracks.empty()){
		mp3_it iter = tracks.find(name);
		if(iter != tracks.end()){
			tracks.erase(name);
		}
	}
}

//delete all mp3 in container
void CTracks::clearTracks( void ){
	if(!tracks.empty()){
		mp3_it	iter;
		for ( iter = tracks.begin(); iter != tracks.end(); ++iter ){
			delete iter->second;
		}
		tracks.clear();
	}
}

//is mp3 in container
bool CTracks::isInCollection( MP3::CMP3Audio* track ){
	
	bool flag = false;

	if(!tracks.empty()){
		mp3_it iter;
		for ( iter = tracks.begin(); iter != tracks.end(); ++iter ) {
			std::string trackName((*(iter->second)).getFileName());
			if(trackName == track->getFileName()){
				flag = true;
			}
		}
	}
	return flag;
}

//get number of mp3Tracks with same title information
const MP3::CTracks::sz_type CTracks::getTitleCount( void ){
	return this->iTitleCount;
}

//is mp3 with this title in container, counts how many times
bool CTracks::isTitleInCollection( MP3::CMP3Audio* track ){
	
	bool flag = false;
	this->iTitleCount = 1;
	
	if(!tracks.empty()){
		
		mp3_it iter;
		for ( iter = tracks.begin(); iter != tracks.end(); ++iter ) {
			std::string trackTitle((*(iter->second)).getTitle());
			if(trackTitle == track->getTitle()){
				++this->iTitleCount;
				flag = true;
			}
		}
	}
	return flag;
}

//is container empty
bool CTracks::isEmpty( void ) const{
	return tracks.empty();
}

//size of mp3 collection
const MP3::CTracks::sz_type CTracks::getSizeOfTracks( void ) const {
	return tracks.size();
}

//begin-iterator
MP3::CTracks::mp3_it CTracks::getBeginIterator( void ) {
	return tracks.begin();
}

//end-iterator
MP3::CTracks::mp3_it CTracks::getEndIterator( void ) {
	return tracks.end();
}

//const_begin-iterator
MP3::CTracks::mp3_const_it CTracks::getBeginIterator( void ) const {
	return tracks.begin();
}

//const_end-iterator
MP3::CTracks::mp3_const_it CTracks::getEndIterator( void ) const {
	return tracks.end();
}