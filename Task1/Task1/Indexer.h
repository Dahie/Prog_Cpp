#pragma once

#include <string>
#include "MP3Audio.h"
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
};

class Indexer
{
protected:
  int num_words; // current length of keypair array
  int capacity; // max length of keypair array
  int growth = 256;
  
  // array holding the keypairs
  KeyPair* list;


public:
  Indexer(void);
  ~Indexer(void);

  void add(std::string& word, MP3::CMP3Audio* mp3audio);
  KeyPair* find(std::string& key) const;
  MP3::CMP3Audio* findFirst(std::string& key) const;
  MP3::CSortedTracks* findAll(std::string& key) const;

};
}
