#include "StdAfx.h"
#include "Tracks.h"

using namespace MP3;

CTracks::CTracks(void)
{
}

CTracks::~CTracks(void)
{
}
	typedef std::list<MP3::MP3Audio*> mp3_cont;		
	typedef mp3_cont::size_type sz_type;
	typedef mp3_cont::iterator mp3_it;
	typedef mp3_cont::const_iterator mp3_const_it;

	//add mp3 with an iterator
	void CTracks::insertTrack(mp3_it iter, MP3::MP3Audio* track) {
		tracks.insert(iter, track);
	}

	//add mp3 at the end of container
	void CTracks::addTrack(MP3::MP3Audio* track) {
		
		tracks.push_back(track);
	}

	//get an mp3
	MP3::MP3Audio* CTracks::getTrack(const std::string& filename) {
		
		if(!tracks.empty()){
			mp3_it iter;
			for ( iter = tracks.begin(); iter != tracks.end(); ++iter ) {
				
				std::string trackFileName((*iter)->getFileName());
				if(trackFileName == filename){
				
					return *iter;
				}
			}
		}
	}

	//delete all mp3 in container
	void CTracks::clearTracks(){

		mp3_it	iter;
		for ( iter = tracks.begin(); iter != tracks.end(); ++iter ){
		
			delete *iter;
		}

		tracks.clear();
	}

	//is container empty
	bool CTracks::isEmpty(void) const{
		return tracks.empty();
	}

	//size of mp3 collection
	const sz_type CTracks::getSizeOfTracks() const {

		return tracks.size();
	}

	//begin-iterator
	mp3_it CTracks::getBeginIterator() {
		return tracks.begin();
	}

	//end-iterator
	mp3_it CTracks::getEndIterator() {
		return tracks.end();
	}

	//const_begin-iterator
	mp3_const_it CTracks::getBeginIterator() const {
		return tracks.begin();
	}

	//const_end-iterator
	mp3_const_it CTracks::getEndIterator() const {
		return tracks.end();
	}
