#pragma once

#include <list>
#include "MP3Audio.h"

namespace MP3{

class CTracks
{
private:
	//type-definition for container
	typedef std::list<MP3::MP3Audio*> mp3_cont;

public:
	CTracks(void);
	~CTracks(void);

	//type-definitions for Size-Type and iterators	
	typedef mp3_cont::size_type sz_type;
	typedef mp3_cont::iterator mp3_it;
	typedef mp3_cont::const_iterator mp3_const_it;

	
	//add mp3 with an iterator
	void insertTrack(mp3_it iter, MP3::MP3Audio* track);

	//add mp3 at the end of container
	void addTrack(MP3::MP3Audio* track);
	
	//get an mp3
	MP3::MP3Audio* getTrack(const std::string& filename);

	//delete all mp3 in container
	void clearTracks();

	//is container empty
	bool isEmpty(void) const;

	//size of mp3 collection
	const sz_type getSizeOfTracks() const ;

	//begin-iterator
	mp3_it getBeginIterator() ;

	//end-iterator
	mp3_it getEndIterator();

	//const_begin-iterator
	mp3_const_it getBeginIterator() const ;

	//const_end-iterator
	mp3_const_it getEndIterator() const;

private:
	mp3_cont tracks;

};//class CTracks

}