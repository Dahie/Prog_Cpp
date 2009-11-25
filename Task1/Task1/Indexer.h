#pragma once
#if !defined(INDEXER_H)
#define INDEXER_H

#include <string>
#include "SortedTitles.h"

namespace Search {

// Element which stores the lookup key 
// and a list of Titles associated with this key
class KeyPair
{
public:
  // key
  const std::string& key;
  // associated list of elements
  // TODO
  MP3::CSortedTitles* list;

  KeyPair(): key("dummy"){
    this->list = new MP3::CSortedTitles();
   };

  KeyPair(const std::string& word): key(word) {
    this->list = new MP3::CSortedTitles();
   };

  KeyPair(const std::string& word, const std::string& title): key(word) {
    this->list = new MP3::CSortedTitles();
    this->list->addTitle(title); //addTitle is unsorted Adding- for sorted use insertTitle
   };
  // no deep copy
  KeyPair(KeyPair* copy): key(copy->key), list(copy->list) {
   };
  ~KeyPair(void){ };


  KeyPair& operator= ( const KeyPair& rhs ) {
    return *this;
  };
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

  // is index empty, nothing indexed yet
  bool is_empty() const;

  // number of indexed words
  unsigned int get_length() const;

  // capacity of the index
  unsigned int get_capacity() const;

  // returns a sorted list of all titles associated with this searchterm
  MP3::CSortedTitles* findAll(const std::string& key) const;

};
}

#endif //INDEXER_H