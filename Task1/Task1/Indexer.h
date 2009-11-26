#pragma once
#if !defined(INDEXER_H)
#define INDEXER_H

#include <string>
#include "SortedTitles.h"

namespace Search {

class KeyPair{ // Element which stores the lookup key and a list of titles associated with this key

public:

	std::string key;
	MP3::CSortedTitles* listTitles;

	Search::KeyPair& Search::KeyPair::operator =( const Search::KeyPair* rhs ) {
		this->key = rhs->key;
		this->listTitles = rhs->listTitles;
		return *this;
	};
	
};//class KeyPair

class Indexer{

public:

	Indexer(void);
	~Indexer(void);

	// insert of several words for one title
	void insert( const std::string& title );
	void insert( const std::string& word, const std::string& title );

	// inserts the word and all possible combinations into the indexer
	// if the word already exists, the title is added to its list
	void insertSingleWord( const std::string& word, const std::string& title );

	//sort list
	void sort( void );

	// remove this title from all indexes
	void remove( const std::string& title );

	// remove all words and titles
	void clearIndices( void );

	// return the KeyPair with the search term
	KeyPair* find( const std::string& key ) const;

	// return the KeyPair / index of the KeyPair with the search term
	KeyPair* findWord( const std::string& key ) const;

	// returns a sorted list of all titles associated with this searchterm
	MP3::CSortedTitles* findAll( const std::string& key ) const;

	// is index empty, nothing indexed yet
	bool is_empty() const;

	// number of indexed words
	unsigned int get_length() const;

	// capacity of the index
	unsigned int get_capacity() const;

	void outputListElements( void );

private:

	 KeyPair* list; // array holding the keypairs
	 
	 unsigned int num_words; // current length of keypair array
	 unsigned int capacity; // max length of keypair array
	 unsigned int growth;
  
	 // recreates the keypair list and increases its length
	 KeyPair* expand();

	 // creates a Keypair object
	 KeyPair* createKeyPair(const std::string& word, const std::string& title);
	 
	 // sort list with mergeSort algorithm
	 void merge( KeyPair* list, int left, int right, int mid );
	 int mergeSort( KeyPair* list, int left, int right );

};//class Indexer

}
#endif //INDEXER_H