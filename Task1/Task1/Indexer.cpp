#include "StdAfx.h"
#include "Indexer.h"
#include <stdio.h>

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

	////get pointer on last character of title
	const char* pLastChar = pText + strlen(pText);

	while( pText <= pLastChar ){
		
		if( *pText == ' ' || pText == pLastChar ){
			if(pText == pLastChar){
				sWord += (*pText);
			}
			this->insert(sWord.c_str(), title);
			//System::Windows::Forms::MessageBox::Show(gcnew System::String(strlen(sWord.c_str()).ToString()));
			sWord = "";
		}else{
			sWord += (*pText);
		}
		++pText;

	}
	// resort list to alphabetical ASC
	this->sort();
}

void Indexer::insert( const std::string& word, const std::string& title ){
  
	size_t word_length = word.length();
	
	// find if the word already exists	
	KeyPair* keypair = findWord(word);

	if( keypair == 0 ) {	// word not yet indexed
		
		// create keypair for word
		KeyPair* keypair = this->createKeyPair(word, title);
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

Search::KeyPair* Indexer::find( const std::string& searchterm ) const {

	// has index values?
	if( this->num_words == 0 ) return 0;

	size_t searchtermLength = strlen(searchterm.c_str());

	//////////////////////////////////////////////////////binary search

	int size = this->get_length();
	int begin = 0;

	while( true ){
		if( begin > size ) return (0); // element not found
		int mid = (begin + size) / 2;

		int comp = this->list[mid].key.compare(0, searchtermLength, searchterm.c_str());

		if( comp == 0) {
			//this->findRest(searchterm, mid);
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
	
	//KeyPair* keypair = this->list; // get first list pointer

	//// logarithmic search
	//signed int delta = (signed int)num_words/2; //warning deleted

	////printf("%s",delta);
	//keypair +=delta;
	////return keypair;
	////int upper_limit = 0;
	////int lower_limit = num_words;
	//int stringcomp = searchterm.compare(keypair->key);

	//while( 
	//(stringcomp != 0) // FIXME breaks when no element found 
	//&& (delta > 0) 
	//)
	//{
	//stringcomp = searchterm.compare(keypair->key);

	//if( stringcomp == 0) {
	//  // strings equal
	//  return keypair;
	//}else if ( strcmp > 0){
	//  // key after current index
	//  //lower_limit = i;
	//  keypair += delta;
	//}else if ( strcmp < 0){
	//  // key before current index
	//  //upper_limit = delta;
	//  keypair -= delta;
	//}
	//}

	return 0;
}

MP3::CSortedTitles* Indexer::findRest( const std::string& searchterm, int mid ){

	MP3::CSortedTitles* resList = new MP3::CSortedTitles();
	//find element which doesnt return searchterm
	//outer limits
	int comp = 0;
	size_t searchtermLength = strlen(searchterm.c_str());


	while( comp == 0){
		int comp = this->list[++mid].key.compare(0, searchtermLength, searchterm.c_str());
		//TODO:add titles to result list //check if title is already in that list
		//resList->insertTitle();
	}
	while( comp == 0){
		int comp = this->list[--mid].key.compare(0, searchtermLength, searchterm.c_str());
		//TODO:add titles to result list
	}

	return resList;
}


MP3::CSortedTitles* Indexer::findAll( const std::string& key ) const {
	
	MP3::CSortedTitles* resList;
	
	// find word, get keypair
	KeyPair* keypair = this->find(key);
	// find all words with this key TODO
	//this->list;
	//this->findWord(key); //returns a list with CSortedTitles
	
	

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
