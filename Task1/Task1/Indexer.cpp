#include "StdAfx.h"
#include "Indexer.h"

Indexer::Indexer(void)
{
}

Indexer::~Indexer(void)
{
}

void Indexer::add(std:string& word, MP3:MP3Audio* mp3audio) 
{
  // find if the word already exists

  // add mp3audio to the words' associated list

}
MP3:MP3Audio* Indexer::findFirst(std:string& key) const
{
  // find word

  // return the first element in the associated list

}

CSortedTracks* Indexer::findAll(std:string& key) const
{
  // find word

  // get list of associated elements

  // return list in SortedTrack-list
}
