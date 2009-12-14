#pragma once
#if !defined(SORTEDTITLES_H)
#define SORTEDTITLES_H

#include <string>

namespace MP3{

class CElement{

	public:
		std::string sTitleName; //TODO: as pointer
		CElement* next;
		CElement* prev;

};//class CNode

/////////////////////////////////////////////////////////////////////////////////////////////

class CSortedTitles{

	class Iter;
	class Const_Iter;

public:
	CSortedTitles( void );
	~CSortedTitles( void );

	//type-definitions for Size-Type and iterators	
	typedef int sz_type;
	typedef Iter iterator;
	typedef Const_Iter const_iterator;

	//sort titles in list
	void sortTitles( void );
	
	//add title at correct position in sorted container
	void insertTitle( const std::string& name );

	//add title at the end of container
	void addTitle( const std::string& name );

	//find a title, if not found return value is NULL
	std::string* findTitle( const std::string& name );
	
	//is title in container
	bool contains(const std::string& title);

	//removes a title
	void removeTitle( const std::string& name );

	//delete all titles in container
	void clearTitles( void );

	//is container empty
	bool isEmpty( void ) const;

	//size of title collection
	const sz_type getSizeOfSortedTitles( void ) const ;

	//begin-iterator
	iterator getBeginIterator( void ) ;

	//end-iterator
	iterator getEndIterator( void );

	//const_begin-iterator
	const_iterator getBeginIterator( void ) const ;

	//const_end-iterator
	const_iterator getEndIterator( void ) const;

	//current iterator
	iterator getCurrentIterator( void );
	void setCurrentIterator( iterator iter );

private:

	CElement* pAnchor;		//pointer to double linked list	
	CElement* pNode;		//working pointer
	sz_type mCounter;		//number of elements in list

	//mergeSort
	CElement* mergeSort( CElement* pList, int stepSize = 1 );

	//Iterator classes
	class Iter {
		CElement* position;
		public:
			Iter(CElement* po) { position = po; }

			CElement* operator->() { return position; } 
			CElement& operator* () { return *position; }
			Iter operator++ ( int ) { Iter it = *this; position++; return it; }
			Iter& operator++ () { position=position->next; return *this; }
			Iter operator-- ( int ) { Iter it = *this; position--; return it; }
			Iter& operator-- () { position=position->prev; return *this; }

			bool Iter::operator== ( const Iter& it ) const { return position == it.position; }
			bool Iter::operator!= ( const Iter& it ) const { return position != it.position; }
	};//class Iter

	class Const_Iter {
		CElement* position;
		public:
			Const_Iter(CElement* po) { position = po; }

			const CElement* operator->() { return position; } 
			const CElement& operator* () { return *position; }
			Const_Iter operator++ (int) { Const_Iter it = *this; position++; return it; }
			Const_Iter& operator++ () { position=position->next; return *this; }
			Const_Iter operator-- (int) { Const_Iter it = *this; position--; return it; }
			Const_Iter& operator-- () { position=position->prev; return *this; }

			bool operator== (const Const_Iter& it) const { return position == it.position; }
			bool operator!= (const Const_Iter& it) const { return position != it.position; }
	};//class Const_Iter

	iterator mCurrenIter;

}; //class CSortedTitles
}
#endif //!defined(SORTEDTITLES_H)