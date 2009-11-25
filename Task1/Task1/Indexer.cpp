
#include "StdAfx.h"
#include "Indexer.h"

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

void Indexer::insert(const std::string& word, const std::string& title) 
{
  size_t word_length = strlen(word.c_str());

  // find if the word already exists
  KeyPair* keypair = 0;
  //KeyPair* keypair = find(word);
  if(keypair == 0) {
    // word not yet indexed

    // create keypair for word
    KeyPair* keypair = new KeyPair(word, title);

    // TODO create keypair for each subvariant of word

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
    new_list[i] = list[i];
  }

  // delete old list
  delete[] list;

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

KeyPair* Indexer::find(const std::string& key) const
{
  KeyPair* keypair = list; // get first list pointer

  // has index values?
  if(num_words == 0)
    return 0;

  // logarithmix search
  signed int delta = (signed int)num_words*0.5;
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


MP3::CSortedTitles* Indexer::findAll(const std::string& key) const
{
   // find word
  KeyPair* keypair = find(key);
  if(keypair != 0) {
  
    // return the first element in the associated list
    return keypair->list;

  } else 
    return 0;
}
