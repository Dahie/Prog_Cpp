#pragma once

#include <string>
#include "SortedTracks.h"

namespace Search {

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

  KeyPair* expand();
  KeyPair* createKeyPair(const std::string& word, const std::string& title);


public:
  Indexer(void);
  ~Indexer(void);

  void add(const std::string& word, const std::string& title);
  KeyPair* find(const std::string& key) const;
  MP3::CSortedTracks* findAll(const std::string& key) const;

};
}

