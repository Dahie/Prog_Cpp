#pragma once
#if !defined(TRACKSEARCHES_H)
#define TRACKSEARCHES_H

#include <map>
#include "SortedTrackInfos.h"
#include "ITrackManager.h"

class CTrackSearches{

	private:
		//type-definition for container
		typedef std::map<TSearchID, CSortedTrackInfos*> tracksearch_cont;


	public:
		CTrackSearches(void);
		~CTrackSearches(void);

		//type-definitions for Size-Type and iterators	
		typedef tracksearch_cont::size_type tracksearch_sz_type;
		typedef tracksearch_cont::iterator tracksearch_it;
		typedef tracksearch_cont::const_iterator tracksearch_const_it;

		void addTrackSearch( const TSearchID id, CSortedTrackInfos* trackInfos );
		CSortedTrackInfos* getTrackSearch( const TSearchID id );
		void removeTrackSearch( const TSearchID id );
		
		//delete all searches in container
		void clearTrackSearches( void );

		//is search in container
		bool isInCollection( const std::string& searchterm );

		//is container empty
		bool isEmpty( void ) const;

		//size of searches collection
		const tracksearch_sz_type getSizeOfTrackSearches( void ) const ;

		//begin-iterators and end-iterators
		tracksearch_it getBeginIterator( void ) ;
		tracksearch_it getEndIterator( void );
		tracksearch_const_it getBeginIterator( void) const ;
		tracksearch_const_it getEndIterator( void ) const;	

	private:
		tracksearch_cont searches;

};//class CTrackSearches

#endif //TRACKSEARCHES_H
