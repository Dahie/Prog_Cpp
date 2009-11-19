#pragma once
#if !defined(SORTEDTRACKS_H)

#define SORTEDTRACKS_H

#include <list>
#include "MP3Audio.h"

namespace MP3{


class CSortedTracks
{

private:
	//type-definition for container
	typedef std::list<std::string> mp3_list;
	
public:
	CSortedTracks(void);
	~CSortedTracks(void);

	//type-definitions for Size-Type and iterators	
	typedef mp3_list::size_type sz_type;
	typedef mp3_list::iterator mp3_it;
	typedef mp3_list::const_iterator mp3_const_it;

	void sortTracks( void );
	
	//add title with an iterator
	void insertTrack(mp3_it iter, const std::string& name);

	//add title at the end of container
	void addTrack(const std::string& name);
	
	//get a title
	std::string getTrack(const std::string& name);

	//removes a title
	void removeTrack(const std::string& name);

	//delete all titles in container
	void clearTracks();

	//is container empty
	bool isEmpty(void) const;

	//size of title collection
	const sz_type getSizeOfSortedTracks() const ;

	//begin-iterator
	mp3_it getBeginIterator() ;

	//end-iterator
	mp3_it getEndIterator();

	//const_begin-iterator
	mp3_const_it getBeginIterator() const ;

	//const_end-iterator
	mp3_const_it getEndIterator() const;

private:
	mp3_list list;
};//class CSortedTracks
}
#endif //SORTEDTRACKS_H