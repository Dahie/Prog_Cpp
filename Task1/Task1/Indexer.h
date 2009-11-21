#pragma once

#include <string>
#include "MP3Audio.h"
#include "SortedTracks.h"


class KeyPair
{
private:
  // key
  std:string& key;
  // associated list of elements
  // TODO
public:
  KeyPair(void);
  KeyPair(std:string& pkey): _key(pkey);
  ~KeyPair(void);

}

class Indexer
{
protected:
  int num_words;
  
  
  KeyPair[] list;


public:
  Indexer(void);
  ~Indexer(void);

  void add(std:string& word, MP3:MP3Audio* mp3audio);
  KeyPair* find(std:string& key) const;
  MP3:MP3Audio* findFirst(std:string& key) const;
  CSortedTracks* findAll(std:string& key) const;

};
