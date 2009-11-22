#include "StdAfx.h"
#include "Indexer.h"
#include "SortedTracks.h";

using namespace Search;


Indexer::Indexer(void)
{
  capacity = growth;
  num_words = 0;
  list = new KeyPair[capacity];
}

Indexer::~Indexer(void)
{
  delete list;
}

void Indexer::add(std::string& word, MP3::CMP3Audio* mp3audio) 
{
  // find if the word already exists
  KeyPair* keypair = find(key);
  if(keypair != 0) {
    // word already exists
    // add mp3audio to the words' associated list
  } else {
    // word not yet indexed

    // create keypair
    KeyPair* keypair;
    keypair->key = word;
// TODOkeypair->list
    keypair->addAudio(mp3audio);

    // find insert index one behind the la
    int insert_index = num_words++;

    // determine if the capacity of the current list is exceeded
    if(insert_index++ > capacity) {
      // number of elements exceeded capacity
      // expand list

      // create new longer list
      KeyPair* new_list = new KeyPair[capacity+growth];

      // copy all elements
      for (int i = 0; i < num_words; ++i) {
        new_list[i] = list[i];
      }

      // delete old list
      delete[] list;

      // replace list
      list = new_list;
    }


    // add keypair to list
      list[insert_index] = keypair;

    // resort list to alphabetical ASC
    // TODO later

  }

}

KeyPair* Indexer::find(std::string& key) const
{
  KeyPair* keypair = list;

  // logarithmix search
  int i = (int)num_words*0.5;
  keypair +=i;
  int upper_limit = 0;
  int lower_limit = num_words;
  int strcmp;

  while(current_keypair->key != key) 
  {
    
    current_keypair = list[i];
    strcmp = strmcmp(current_keypair->word, key );



    if( strcmp == 0) {
      // strings equal
      return pointer;
    else if ( strcmp > 0){
      // key after current index
      lower_limit = i;
      i 
      pointer += 
    else if ( strcmp < 0){
      // key before current index
      upper_limit = i;
    }



    if( strcmp == 0) {
      // strings equal
      return keypair;
    else if ( strcmp > 0){
      // key after current index
      lower_limit = i;
      i = upper_limit / lower_limit;
    else if ( strcmp < 0){
      // key before current index
      upper_limit = i;
    }  
  }

  return -1;
}

    MP3::CMP3Audio* Indexer::findFirst(std::string& key) const
{
 

  

}

    CSortedTracks* Indexer::findAll(std::string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  if(keypair != 0) {
  
    // return the first element in the associated list
    return keypair->list;

  } else 
    return 0;
}
