#pragma once

#include <string>
#include "MP3Audio.h"
#include "SortedTracks.h"

namespace Search {

struct KeyPair
{
  // key
  std:string& key;
  // associated list of elements
  // TODO
  list
}

class Indexer
{
protected:
  int num_words; // current length of keypair array
  int capacity; // max length of keypair array
  int growth = 256;
  
  // array holding the keypairs
  KeyPair*[] list;


public:
  Indexer(void);
  ~Indexer(void);

  void add(std:string& word, MP3:MP3Audio* mp3audio);
  KeyPair* find(std:string& key) const;
  MP3:MP3Audio* findFirst(std:string& key) const;
  CSortedTracks* findAll(std:string& key) const;

};
}
