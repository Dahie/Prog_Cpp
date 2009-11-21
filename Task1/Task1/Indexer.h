#pragma once

#include <string>
#include "MP3Audio.h"
#include "SortedTracks.h"


class Indexer
{
public:
  Indexer(void);
  ~Indexer(void);

  void add(std:string& word, MP3:MP3Audio* mp3audio);
  MP3:MP3Audio* findFirst(std:string& key) const;
  CSortedTracks* findAll(std:string& key) const;

};
