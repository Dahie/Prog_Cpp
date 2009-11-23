#include "StdAfx.h"
#include "SortedTitles.h"

using namespace MP3;

CSortedTitles::CSortedTitles ( void ): pAnchor(new CElement()), pNode(NULL), mCounter(0)
{
	if( !pAnchor ){ 
		System::Windows::Forms::MessageBox::Show("\nERROR: No memory access. Some components failed to load.\n\n"+
		"\n              ----- MP3Tagger will be closed. -----\n\n\n         Please try to restart the application later!!!\n\n\n","MP3 Tagger",
		System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		exit(0); 
	}
	
	//dummy element
	pAnchor->next = pAnchor;
	pAnchor->prev = pAnchor;
	pAnchor->sTitleName = "";

}

CSortedTitles::~CSortedTitles( void )
{	
	this->clearTitles();
	if( !pNode ){ delete pNode; }
	delete pAnchor;
}

//add title at correct position in sorted container
void CSortedTitles::insertTitle( const std::string& name ){
	
	pNode = pAnchor->next;

	while( pNode!=pAnchor && pNode->sTitleName < name ){
		pNode = pNode->next;
	}

	CElement* pNew = new CElement();
	if( !pNew ) { /*ERROR*/	return; }

	pNew->sTitleName = name;
	pNew->prev = pNode->prev;
	pNew->next = pNode;
	
	pNode->prev->next = pNew;
	pNode->prev = pNew;

	++(this->mCounter);
}

//add title at the end of container
void CSortedTitles::addTitle (const std::string& name ){

	CElement* pNew = new CElement(); //create new element
	if( !pNew ) { /*ERROR*/	return; }

	pNew->sTitleName = name;
	pNew->prev = pAnchor->prev;		//prev element is old last element
	pNew->next = pAnchor;			//last element's next is dummy element

	if(this->isEmpty()){			
		pAnchor->next = pNew;		//dummy element's next is new last element
	}else{
		pAnchor->prev->next = pNew; //old last element's next is new last element
	}
	
	pAnchor->prev = pNew;			//set new last element
	++(this->mCounter);				//increment element counter
}

//find a title, if not found return value is NULL
std::string* CSortedTitles::findTitle( const std::string& name ){

	if(!isEmpty()){
		pNode = pAnchor->next;
		while( pNode->sTitleName != name ){
			pNode = pNode->next;
			if(pNode == pAnchor) return NULL; //"<title not found>"
		}
		return &(pNode->sTitleName);
	}
	return NULL; //"<empty title list>"
}

//removes a title
void CSortedTitles::removeTitle( const std::string& name ){

	pNode = pAnchor->next;

	while( pNode != pAnchor && pNode->sTitleName != name ){
		pNode = pNode->next;
	}

	if( pNode == pAnchor) return; //element was not found

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	//delete pNode->sTitleName; //TODO: if it is a pointer
	delete pNode;
	--(this->mCounter);
}

//delete all titles in container
void CSortedTitles::clearTitles( void ){

	if(!isEmpty()){

		pNode = pAnchor->prev; //last element
		CElement* node = NULL;

		while( pNode != pAnchor ){
			node = pNode;
			pNode = pNode->prev;
			delete node;
		}

		pAnchor->next = pAnchor;
		pAnchor->prev = pAnchor;
		pNode = NULL;

		this->mCounter = 0;
	}
}

//is container empty
bool CSortedTitles::isEmpty( void ) const{

	bool flag = false;
	if((pAnchor->next) == pAnchor){
		flag = true;
	}
	return flag;
}

//size of title collection
const MP3::CSortedTitles::sz_type CSortedTitles::getSizeOfSortedTitles( void ) const {
	return this->mCounter;
}

//begin-iterator
MP3::CSortedTitles::iterator CSortedTitles::getBeginIterator( void ){
	return iterator(pAnchor->next);
}

//end-iterator
MP3::CSortedTitles::iterator CSortedTitles::getEndIterator( void ){
	return iterator(pAnchor);
}

//const_begin-iterator
MP3::CSortedTitles::const_iterator CSortedTitles::getBeginIterator( void ) const {
	return const_iterator(pAnchor->next);
}

//const_end-iterator
MP3::CSortedTitles::const_iterator CSortedTitles::getEndIterator( void ) const {
	return const_iterator(pAnchor);
}