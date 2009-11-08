#include "StdAfx.h"
#include "SortedTracks.h"

using namespace MP3;

CSortedTracks::CSortedTracks(void)
{
}

CSortedTracks::~CSortedTracks(void)
{
}

	typedef std::list<std::string> mp3_list;		
	typedef mp3_list::size_type sz_type;
	typedef mp3_list::iterator mp3_it;
	typedef mp3_list::const_iterator mp3_const_it;

	//add title with an iterator
	void CSortedTracks::insertTrack(mp3_it iter, const std::string& name) {
		list.insert(iter, name);
	}

	//add title at the end of container
	void CSortedTracks::addTrack(const std::string& name) {
		list.push_back(name);
	}

	//get a title
	std::string CSortedTracks::getTrack(const std::string& name) {
		
		if(!list.empty()){
			mp3_it iter;
			for ( iter = list.begin(); iter != list.end(); ++iter ) {
				if((*iter) == name){
					return *iter;
				}
			}
		}
		return "";
	}

	//remove a title
	void CSortedTracks::removeTrack(const std::string& name){
		list.remove(name);
	}

	//sort titles
	void CSortedTracks::sortTracks( void ){
		list.sort();
	}

	//delete all titles in container
	void CSortedTracks::clearTracks(){
		list.clear();
	}

	//is container empty
	bool CSortedTracks::isEmpty(void) const{
		return list.empty();
	}

	//size of title collection
	const sz_type CSortedTracks::getSizeOfSortedTracks() const {
		return list.size();
	}

	//begin-iterator
	mp3_it CSortedTracks::getBeginIterator() {
		return list.begin();
	}

	//end-iterator
	mp3_it CSortedTracks::getEndIterator() {
		return list.end();
	}

	//const_begin-iterator
	mp3_const_it CSortedTracks::getBeginIterator() const {
		return list.begin();
	}

	//const_end-iterator
	mp3_const_it CSortedTracks::getEndIterator() const {
		return list.end();
	}

