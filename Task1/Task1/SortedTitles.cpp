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
	
	//head element
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
	pNew->next = pAnchor;			//last element's next is head

	if(this->isEmpty()){			
		pAnchor->next = pNew;		//head's next is new last element
	}else{
		pAnchor->prev->next = pNew; //old last element's next is new last element
	}
	
	pAnchor->prev = pNew;			//set new last element
	++(this->mCounter);				//increment element counter
}

//find a title, if not found return value is NULL
std::string* CSortedTitles::findTitle( const std::string& name ) {

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

	delete pNode;
	--(this->mCounter);
}

bool MP3::CSortedTitles::contains(const std::string& title) {
  return ( this->findTitle(title) != 0 );
}

//delete all titles in container
void MP3::CSortedTitles::clearTitles( void ){

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
bool MP3::CSortedTitles::isEmpty( void ) const{
	return (this->mCounter > 0 ? false : true);
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

void MP3::CSortedTitles::sortTitles( void ){
	this->mergeSort( this->pAnchor );
}

//returns new head of the list
MP3::CElement* MP3::CSortedTitles::mergeSort( MP3::CElement* pList, int stepSize ){

	MP3::CElement* pLeftList,* pRightList,* pOldHead,* pBuffer;
	int iLeftListSize, iRightListSize, numberOfMerges;

	if(!pList){ return NULL; }

	pLeftList = pList;	//pointer to head of double linked list which is circular linked
	pOldHead = pList;	//save pointer to old head
	pList = NULL;
	pBuffer = NULL;

	numberOfMerges = 0;

	while( NULL != pLeftList ){
	
		++numberOfMerges; //increment number of merges

		//iterate to element which is "stepSize" next from pLeftList 
		pRightList = pLeftList;
		iLeftListSize = 0;

		for( int i = 0; i < stepSize; ++i ){
			
			++iLeftListSize;
			//check if next is the end of original list if not it is first of right list
			pRightList = (pRightList->next == pOldHead ? NULL : pRightList->next);	
			if ( !pRightList ){ break; } //end of list
		}

		iRightListSize = stepSize;	//set size of right list

		//merge  lists
		while( (iLeftListSize > 0) || ( (iRightListSize > 0) && (NULL != pRightList) )){

			MP3::CElement* resultElement;

			//next element for merge list comes from left or right list
			if( iLeftListSize == 0 ){
				
				//left list is empty, element comes from right list
				resultElement = pRightList;
				pRightList = pRightList->next;
				--iRightListSize;
				
				if( pRightList == pOldHead ){ pRightList = NULL; } //end of list

			}else if( iRightListSize == 0 || !pRightList ){
				
				//right list is empty, element comes from left list
				resultElement = pLeftList;
				pLeftList = pLeftList->next;
				--iLeftListSize;
				if( pLeftList == pOldHead ){ pLeftList = NULL; } //end of list
				

			}else if( (pLeftList->sTitleName) <= (pRightList->sTitleName) ){
				
				/* First element of left list is smaller or same, element comes from left list. */
				resultElement = pLeftList;
				pLeftList = pLeftList->next;
				--iLeftListSize;

				if( pLeftList == pOldHead ){ pLeftList = NULL; } //end of list

			}else{

				/* First element of right list is smaller, element comes from right list. */
				resultElement = pRightList;
				pRightList = pRightList->next;
				--iRightListSize;

				if( pRightList == pOldHead ){ pRightList = NULL; } //end of list
			}

            //add the result element to the merged list
			if( NULL != pBuffer ){
				pBuffer->next = resultElement;
			}else{
				pList = resultElement;	//pList points to first resultElement
			}
			resultElement->prev = pBuffer;
			pBuffer = resultElement;

		}//end of while resultElement

		//pointer of left list points now on end of right list - both interated over "stepSize" elements
        pLeftList = pRightList;
	
	}//end of while( NULL != pLeftList )

	pBuffer->next = pList;		//set next-pointer of last element to head
	pList->prev = pBuffer;		//set prev-pointer of head to last element
	
	if( numberOfMerges <= 1 ){	//terminat if only 1 merge was done or list is empty
        return pList;
	}else{						//repeat with double merging list size
		stepSize *= 2;
		this->mergeSort(pList,stepSize);
	}
	return NULL;
}