#include <stdio.h>
#include <string.h>
#include "StdAfx.h"
#include "Indexer.h"
#include "SortedTracks.h"


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

void Indexer::insert(const std::string& word, const std::string& title) 
{
  size_t word_length = strlen(word.c_str());

  // find if the word already exists
  KeyPair* keypair = find(word);
  if(keypair == 0) {
    // word not yet indexed

    // create keypair for word
    KeyPair* keypair = createKeyPair(word, title);
    // create keypair for each subvariant of word

    // find insert index one behind the la
    unsigned int insert_index = num_words++;

    // determine if the capacity of the current list is exceeded
    if(insert_index++ > capacity) {
      // number of elements exceeded capacity
      // expand list and replace old list
      list = expand();
    }


    // add keypairs to list
    list[insert_index] = keypair;

    // resort list to alphabetical ASC
    // TODO later

  }

}

KeyPair* Indexer::expand() {
 // create new longer list
      KeyPair* new_list = new KeyPair[capacity+growth];

      // copy all elements
      for (signed int i = 0; i < num_words; ++i) {
        new_list[i] = list[i];
      }

      // delete old list
      delete[] list;

      // replace list
      return new_list;
}

KeyPair* Indexer::createKeyPair(const std::string& word, const std::string& title)
{
  KeyPair* keypair = new KeyPair();
  keypair->key = word;
  keypair->list->addTrack(title);
  return keypair;
}

KeyPair* Indexer::find(const std::string& key) const
{
  KeyPair* keypair = list; // get first list pointer

  // logarithmix search
  unsigned int delta = (unsigned int)num_words*0.5;
  keypair +=delta;
  //int upper_limit = 0;
  //int lower_limit = num_words;
  int stringcomp = strcmp( (keypair->key).c_str(), key.c_str() );

  while( 
    stringcomp != 0) // FIXME breaks when no element found 
  {
    stringcomp = strcmp( (keypair->key).c_str(), key.c_str() );


    if( strcmp == 0) {
      // strings equal
      return keypair;
    }else if ( strcmp > 0){
      // key after current index
      //lower_limit = i;
      keypair += delta;
    }else if ( strcmp < 0){
      // key before current index
      //upper_limit = delta;
    }


/*
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
    }*/  
  }

  return 0;
}


MP3::CSortedTracks* Indexer::findAll(const std::string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  if(keypair != 0) {
  
    // return the first element in the associated list
    return keypair->list;

  } else 
    return 0;
}
