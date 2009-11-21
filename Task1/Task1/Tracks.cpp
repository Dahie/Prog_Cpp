#include "StdAfx.h"
#include "Tracks.h"
#include <list>

using namespace MP3;

CTracks::CTracks(void): iTitleCount(0)
{
}

CTracks::~CTracks(void)
{
}

	typedef std::map<std::string, MP3::CMP3Audio*> mp3_cont;		
	typedef mp3_cont::size_type sz_type;
	typedef mp3_cont::iterator mp3_it;
	typedef mp3_cont::const_iterator mp3_const_it;

	//add mp3 at the end of container
	void CTracks::addTrack( const std::string& name, MP3::CMP3Audio* track ) {
			tracks[name]=track;
	}

	//get a mp3
	MP3::CMP3Audio* CTracks::getTrack( const std::string& name ) {
		
		if(!tracks.empty()){

			mp3_it iter = tracks.find(name);
			if(iter != tracks.end()){
				return iter->second;
			}
			/*mp3_it iter;
			for ( iter = tracks.begin(); iter != tracks.end(); ++iter ) {
				if((iter->first) == name){
					return iter->second;
				}
			}*/
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

	//delete all mp3 in container
	void CTracks::clearTracks( void ){

		mp3_it	iter;
		for ( iter = tracks.begin(); iter != tracks.end(); ++iter ){
			delete iter->second;
		}
		tracks.clear();
	}

	//get number of mp3Tracks with same title information
	int CTracks::getTitleCount( void ){
		return this->iTitleCount;
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

	//is mp3 with this title in container, counts how many times
	bool CTracks::isTitleInCollection( MP3::CMP3Audio* track ){
		
		bool flag = false;
		this->iTitleCount = 1;

		if(!tracks.empty()){
			
			mp3_it iter;
			for ( iter = tracks.begin(); iter != tracks.end(); ++iter ) {
				std::string trackName((*(iter->second)).getTitle());
				if(trackName == track->getTitle()){
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
	const sz_type CTracks::getSizeOfTracks( void ) const {
		return tracks.size();
	}

	//begin-iterator
	mp3_it CTracks::getBeginIterator( void ) {
		return tracks.begin();
	}

	//end-iterator
	mp3_it CTracks::getEndIterator( void ) {
		return tracks.end();
	}

	//const_begin-iterator
	mp3_const_it CTracks::getBeginIterator( void ) const {
		return tracks.begin();
	}

	//const_end-iterator
	mp3_const_it CTracks::getEndIterator( void ) const {
		return tracks.end();
	}