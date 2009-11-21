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
  // logarithmic/binary search

  // add mp3audio to the words' associated list

}

KeyPair* Indexer::find(std:string& key) const
{
  KeyPair* keypair

  // logarithmix search
  int i = (int)num_words*0.5;
  while(current_keypair->key != key) 
  {
    
    current_keypair = list[i];
    
  }

  // return the found keypair
  return keypair*
}

MP3:MP3Audio* Indexer::findFirst(std:string& key) const
{
 

  

}

CSortedTracks* Indexer::findAll(std:string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  if(keypair != 0) {
  
    // return the first element in the associated list
    keypair->set

  } else 
    return 0;
}
