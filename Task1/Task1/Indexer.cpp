
#include "StdAfx.h"
#include "Indexer.h"
#include <stdio.h>

using namespace Search;

Indexer::Indexer(void)
{
  capacity = growth;
  num_words = 0;
  list = new KeyPair[capacity];
}

Indexer::~Indexer(void)
{
  delete[] list;
}

void Indexer::insert(const std::string* words, const unsigned int num, const std::string& title) 
{
  
  for(unsigned int i=0;i<num;++i) {
  
    // find if the word already exists
    KeyPair* keypair = 0;
    //KeyPair* keypair = find(word);
    if(keypair == 0) {
      // word not yet indexed

      // create keypair for word
      KeyPair* keypair = new KeyPair(*words, title);

      // TODO create keypair for each subvariant of word

      // find insert index one behind the la
      unsigned int insert_index = num_words;

      // determine if the capacity of the current list is exceeded
      if(insert_index >= capacity) {
        // number of elements exceeded capacity
        // expand list and replace old list
        list = expand();
      }


      // add keypairs to list
      list[insert_index] = keypair;
      this->num_words++;
      words++;
    }
    // resort list to alphabetical ASC
    // TODO later
  }
}


void Indexer::insert(const std::string& word, const std::string& title) 
{
  size_t word_length = word.length();

  // find if the word already exists
  KeyPair* keypair = 0;
  //KeyPair* keypair = find(word);
  if(keypair == 0) {
    // word not yet indexed

    // create keypair for word
    KeyPair* keypair = new KeyPair(word, title);

    // TODO create keypair for each subvariant of word

    // find insert index one behind the la
    unsigned int insert_index = this->num_words;

    // determine if the capacity of the current list is exceeded
    if(insert_index >= this->capacity) {
      // number of elements exceeded capacity
      // expand list and replace old list
      this->list = expand();
    }


    // add keypairs to list
    this->list[insert_index] = keypair;
    this->list;
    this->num_words++;

    // resort list to alphabetical ASC
    // TODO later

  }
}

void Indexer::remove(const std::string& title) 
{
  KeyPair* keypair = 0;
  for(unsigned int i = 0; i < num_words; ++i){
    this->list[i].list->removeTitle(title);
  }
  // TODO remove unused index word
}

KeyPair* Indexer::expand() {
  // create new longer list
  KeyPair* new_list = new KeyPair[capacity+growth];

  // copy all elements
  for (unsigned int i = 0; i < num_words; ++i) {
    new_list[i] = this->list[i];
  }

  // delete old list
  delete[] this->list;

  // replace list
  return new_list;
}

KeyPair* Indexer::createKeyPair(const std::string& word, const std::string& title)
{
  KeyPair* keypair = new KeyPair(word, title);
  return keypair;
}

bool Indexer::is_empty() const
{
  return (num_words > 0) ? false : true;
}

unsigned int Indexer::get_length() const
{
  return this->num_words;
}

unsigned int Indexer::get_capacity() const
{
  return this->capacity;
}

KeyPair* Indexer::find(const std::string& searchterm) const
{
  KeyPair* keypair = this->list; // get first list pointer

  // has index values?
  if(this->num_words == 0)
    return 0;

  

  // logarithmic search
  signed int delta = (signed int)num_words*0.5;
  
  //printf("%s",delta);
  keypair +=delta;
  return keypair;
  //int upper_limit = 0;
  //int lower_limit = num_words;
  int stringcomp = searchterm.compare(keypair->key);

  /*while( 
    (stringcomp != 0) // FIXME breaks when no element found 
    && (delta > 0) 
    )
  {
    stringcomp = searchterm.compare(keypair->key);

    if( stringcomp == 0) {
      // strings equal
      return keypair;
    }else if ( strcmp > 0){
      // key after current index
      //lower_limit = i;
      keypair += delta;
    }else if ( strcmp < 0){
      // key before current index
      //upper_limit = delta;
      keypair -= delta;
    }
  }*/

  return 0;
}


MP3::CSortedTitles* Indexer::findAll(const std::string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  keypair->list;
  keypair->key;
  this->list;
  if(keypair != 0) {
  
    // return the first element in the associated list
    return keypair->list;

  } else 
    return 0;
}
