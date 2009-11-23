#include "StdAfx.h"
#include "Indexer.h"
#include "SortedTracks.h"
#include <stdio.h>
#include <string.h>

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

void Indexer::add(const std::string& word, const std::string& title) 
{
  // find if the word already exists
  KeyPair* keypair = find(word);
  if(keypair == 0) {
    // word not yet indexed

    // create keypair
    KeyPair* keypair;
    keypair->key = word;
    keypair->list->addTrack(title);

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

KeyPair* Indexer::find(const std::string& key) const
{
  KeyPair* keypair = list;

  // logarithmix search
  int delta = (int)num_words*0.5;
  keypair +=delta;
  //int upper_limit = 0;
  //int lower_limit = num_words;
  int strcmp = strncmp(keypair->key, key );

  while( 
    strcmp != 0) // FIXME breaks when no element found 
  {
    strcmp = strncmp(keypair->key, key );


    if( strcmp == 0) {
      // strings equal
      return keypair;
    else if ( strcmp > 0){
      // key after current index
      //lower_limit = i;
      i 
      pointer += delta;
    else if ( strcmp < 0){
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

  return -1;
}


CSortedTracks* Indexer::findAll(const std::string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  if(keypair != 0) {
  
    // return the first element in the associated list
    return keypair->list;

  } else 
    return 0;
}
