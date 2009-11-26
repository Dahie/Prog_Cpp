#include "StdAfx.h"
#include "Indexer.h"
#include <stdio.h>
#include <algorithm>

using namespace Search;

Indexer::Indexer(void): growth(256)
{
  capacity = growth;
  num_words = 0;
  list = new KeyPair[capacity]; //TODO
}

Indexer::~Indexer(void)
{
  delete[] list;
}

void Indexer::insert( const std::string& title ){
  
	const char* pText = title.c_str();
	std::string sWord="";

	//get pointer on last character of title
	const char* pLastChar = pText + strlen(pText);

	while( pText <= pLastChar ){
		
		if( *pText == ' ' || pText == pLastChar ){
			if(pText == pLastChar){
				sWord += (*pText);
			}
			this->insert(sWord.c_str(), title);
			sWord = "";
		}else{
			sWord += (*pText);
		}
		++pText;

	}
	// resort list to alphabetical ASC
	this->sort();
}

void Indexer::insert( const std::string& word, const std::string& title )
{
  // split each word into substring
  for(size_t l = 1; l < word.length()+1; ++l) {
    std::string subword = word.substr(0, l);
    this->insertSingleWord(subword, title);
  }
}

void Indexer::insertSingleWord( const std::string& word, const std::string& title )
{
  std::string word_lowercase = word;
  std::transform(word_lowercase.begin(), word_lowercase.end(), word_lowercase.begin(), tolower);

	// find if the word already exists	
	KeyPair* keypair = findWord(word_lowercase);

	if( keypair == 0 ) {	// word not yet indexed
		
		// create keypair for word
		KeyPair* keypair = this->createKeyPair(word_lowercase, title);
		// TODO create keypair for each subvariant of word

		// find insert index one behind the la
		unsigned int insert_index = this->num_words;
		// determine if the capacity of the current list is exceeded
		if( insert_index >= this->capacity ){
		  // number of elements exceeded capacity
		  // expand list and replace old list
		  this->list = expand();
		}
		  
		// add keypair to list 
		this->list[insert_index] = keypair;
		++this->num_words;

	}else{					//add title to this indexed word
    if(!(keypair->listTitles->contains(title)))
		keypair->listTitles->insertTitle(title);
	}
}

void Indexer::sort( void ){
	int size = this->get_length()-1;
	this->mergeSort(this->list, 0, size);
}

int Indexer::mergeSort( KeyPair* list, int left, int right ){
	int mid;
	if( left < right ){
		mid = ( left+right )/2;
		mergeSort(list, left, mid);
		mergeSort(list, mid+1, right);
		merge(list, left, right, mid);
	}
	return(0);
}

void Indexer::merge( KeyPair* list, int left, int right, int mid ){

	KeyPair* buffer = new KeyPair[this->get_capacity()];
	int indexLeft = left;
	int indexRight = mid+1;
	int indexBuffer = left;

	while( (indexLeft <= mid) && (indexRight <= right) ){
		if( list[indexLeft].key < list[indexRight].key ){
			buffer[indexBuffer] = list[indexLeft];
			indexBuffer++;
			indexLeft++;
		}else{
			buffer[indexBuffer] = list[indexRight];
			indexBuffer++;
			indexRight++;
		}
	}
	while( indexLeft <= mid ){
		buffer[indexBuffer] = list[indexLeft];
		indexBuffer++;
		indexLeft++;
	}
	while( indexRight <= right ){
		buffer[indexBuffer] = list[indexRight];
		indexBuffer++;
		indexRight++;
	}
	for( int i=left; i<indexBuffer; i++){
		list[i] = buffer[i];
	}
} 

void Indexer::remove( const std::string& title ){

	KeyPair* keypair = 0;
	for( unsigned int i = 0; i < num_words; ++i ){
		this->list[i].listTitles->removeTitle(title);
		//remove unused index word
		if(this->list[i].listTitles->isEmpty()){
			this->list[i].key = "";
			--this->num_words;
		}
	}
	this->sort();
}

void Indexer::clearIndices( void ){
	if(this->is_empty()) return;
	KeyPair* keypair = 0;
	for( unsigned int i = 0; i < this->get_length(); ++i){
		keypair = &this->list[i];
		keypair->listTitles->clearTitles();
		keypair->key = "";
		delete keypair->listTitles;
	}
	this->num_words = 0;
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

KeyPair* Indexer::createKeyPair( const std::string& word, const std::string& title ){
	KeyPair* keypair = new KeyPair();
	keypair->key = word;
	keypair->listTitles = new MP3::CSortedTitles();
	keypair->listTitles->insertTitle(title);
	return keypair;
}

bool Indexer::is_empty() const {
	return (num_words > 0) ? false : true;
}

unsigned int Indexer::get_length() const {
	return this->num_words;
}

unsigned int Indexer::get_capacity() const {
	return this->capacity;
}

Search::KeyPair* Indexer::findWord( const std::string& searchterm ) const {

	// has index values?
	if( this->num_words == 0 ) return 0;

	int size = this->get_length();
	int begin = 0;

	while( true ){
		if( begin > size ) return (0); // element not found
		int mid = (begin + size) / 2;

		int comp = this->list[mid].key.compare(searchterm.c_str());

		if( comp == 0) {
			return &this->list[mid];
		}else{
			if( comp < 0 ){
				begin = mid + 1 ;	//element is in upper area
			}
			if( comp > 0 ){
				size = mid - 1;		//element is in bottom area
			}
		}
	}
	return 0;
}

Search::KeyPair* Indexer::find(const std::string& searchterm) const {

	// has index values?
	if( this->num_words == 0 ) return 0;

	int size = this->get_length();
	int begin = 0;

	while( true ){
		if( begin > size ) return (0); // element not found
		int mid = (begin + size) / 2;

		int comp = this->list[mid].key.compare(searchterm.c_str());

		if( comp == 0) {
			return &this->list[mid];		
		}else{
			if( comp < 0 ){
				begin = mid + 1 ;	//element is in upper area
			}
			if( comp > 0 ){
				size = mid - 1;		//element is in bottom area
			}
		}
	}
	
	return 0;
}


MP3::CSortedTitles* Indexer::findAll( const std::string& key ) const {
	
	MP3::CSortedTitles* resList;
	
	// find word, get keypair
	KeyPair* keypair = this->findWord(key);

	if(keypair != 0) {

		//save title list
		resList = keypair->listTitles;
		// return the first element in the associated list
		return resList;
	}

	return 0;
}

void Indexer::outputListElements( void ){

	for( unsigned int i = 0; i < this->get_length(); ++i ){
		System::Windows::Forms::MessageBox::Show("::"+gcnew System::String(this->list[i].key.c_str())+"::");
	}
}
