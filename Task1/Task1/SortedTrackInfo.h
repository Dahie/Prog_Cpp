#pragma once
#if !defined(SORTEDTRACKINFO_H)
#define SORTEDTRACKINFO_H

#include <vector>
#include "ITrackManager.h"

class CSortedTrackInfo
{
	private:
		//type definition for container
		typedef std::vector<CTrackInfo> mapp_cont;

	public:
		CSortedTrackInfo(void);
		~CSortedTrackInfo(void);

		//type definition for size-type and iterators
		typedef mapp_cont::size_type mapp_sz_type;
		typedef mapp_cont::iterator mapp_it;
		typedef mapp_cont::const_iterator mapp_const_it;

		//sort elements in vector
		void sortElements( void );

		//add element at the end of container
		void addElement( CTrackInfo trackInfo );

		//get element by index
		const CTrackInfo& getElement( const mapp_sz_type index ) const;
		CTrackInfo& getElement( const mapp_sz_type index );

		//get element by title name
		CTrackInfo& getElement( const std::string& name);

		//removes an element
		void removeElement( const mapp_sz_type index );

		//delete all elements in container
		void clearElements( void );

		//contains an element
		bool contains( const CTrackInfo trackInfo );//find title

		//is container empty
		bool isEmpty( void ) const;

		//size of mapping collection
		const mapp_sz_type getSizeOfSortedMapping( void ) const ;
		
		//begin-iterator
		mapp_it getBeginIterator( void ) ;

		//end-iterator
		mapp_it getEndIterator( void );

		//const_begin-iterator
		mapp_const_it getBeginIterator( void) const ;

		//const_end-iterator
		mapp_const_it getEndIterator( void ) const;

	private:
		mapp_cont vec;

		// sort vector with mergeSort algorithm
		void merge( mapp_cont& vec, int left, int right, int mid );
		int mergeSort( mapp_cont& vec, int left, int right );

};//class CSortedMapping

#endif //SORTEDTRACKINFO_H