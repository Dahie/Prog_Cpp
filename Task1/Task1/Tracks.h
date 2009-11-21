#pragma once
#if !defined(TRACKS_H)
#define TRACKS_H

#include <map>
#include "MP3Audio.h"

namespace MP3{

class CTracks
{
private:
	//type-definition for container
	typedef std::map<std::string, MP3::CMP3Audio*> mp3_cont;
	int iTitleCount;

public:
	CTracks(void);
	~CTracks(void);

	//type-definitions for Size-Type and iterators	
	typedef mp3_cont::size_type sz_type;
	typedef mp3_cont::iterator mp3_it;
	typedef mp3_cont::const_iterator mp3_const_it;

	//get number of equal titles
	int getTitleCount( void );

	//add mp3 at the end of container
	void addTrack( const std::string& name, MP3::CMP3Audio* track );
	
	//get a mp3
	MP3::CMP3Audio* getTrack( const std::string& name );

	//delete a mp3
	void removeTrack( const std::string& name );

	//is mp3 in container
	bool isInCollection( MP3::CMP3Audio* track );

	//is mp3 with this title in container, counts how many times
	bool isTitleInCollection(MP3::CMP3Audio* track);

	//delete all mp3 in container
	void clearTracks( void );

	//is container empty
	bool isEmpty( void ) const;

	//size of mp3 collection
	const sz_type getSizeOfTracks( void ) const ;

	//begin-iterator
	mp3_it getBeginIterator( void ) ;

	//end-iterator
	mp3_it getEndIterator( void );

	//const_begin-iterator
	mp3_const_it getBeginIterator( void) const ;

	//const_end-iterator
	mp3_const_it getEndIterator( void ) const;

private:
	mp3_cont tracks;

};//class CTracks

}
#endif //TRACKS_H