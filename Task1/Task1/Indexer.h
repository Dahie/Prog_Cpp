#pragma once

#include <string>
#include "SortedTracks.h"

namespace Search {

// Element which stores the lookup key 
// and a list of Titles associated with this key
class KeyPair
{
public:
  // key
  std::string& key;
  // associated list of elements
  // TODO
  MP3::CSortedTracks* list;

  KeyPair(void);
  KeyPair(KeyPair*);
  ~KeyPair(void);


KeyPair& operator= ( const KeyPair& rhs );
};

class Indexer
{
protected:
  unsigned int num_words; // current length of keypair array
  unsigned int capacity; // max length of keypair array
  const static unsigned int growth = 256;
  
  // array holding the keypairs
  KeyPair* list;

  // recreates the keypair list and increases its length
  KeyPair* expand();

  // creates a Keypair object
  KeyPair* createKeyPair(const std::string& word, const std::string& title);


public:
  Indexer(void);
  ~Indexer(void);

  // inserts the word and all possible combinations into the indexer
  // if the word already exists, the title is added to its list
  void insert(const std::string& word, const std::string& title);

  // return the KeyPair with the search term
  KeyPair* find(const std::string& key) const;

  // returns a sorted list of all titles associated with this searchterm
  MP3::CSortedTracks* findAll(const std::string& key) const;

};
}

