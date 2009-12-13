#include "StdAfx.h"
#include "SortedTrackInfo.h"

CSortedTrackInfo::CSortedTrackInfo(void){
}

CSortedTrackInfo::~CSortedTrackInfo(void){
}

//sort elements in list
void CSortedTrackInfo::sortElements( void ){
	int size = this->getSizeOfSortedMapping()-1;
	this->mergeSort(this->vec, 0, size);
}

int CSortedTrackInfo::mergeSort( mapp_cont& vec, int left, int right ){
	int mid;
	if( left < right ){
		mid = ( left+right )/2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid+1, right);
		merge(vec, left, right, mid);
	}
	return(0);
}

void CSortedTrackInfo::merge( mapp_cont& vec, int left, int right, int mid ){

	std::vector<CTrackInfo> buffer = vec;
	int indexLeft = left;
	int indexRight = mid+1;
	int indexBuffer = left;

	while( (indexLeft <= mid) && (indexRight <= right) ){
		if( vec[indexLeft].mTitle < vec[indexRight].mTitle){
			buffer[indexBuffer] = vec[indexLeft];
			indexBuffer++;
			indexLeft++;
		}else{
			buffer[indexBuffer] = vec[indexRight];
			indexBuffer++;
			indexRight++;
		}
	}
	while( indexLeft <= mid ){
		buffer[indexBuffer] = vec[indexLeft];
		indexBuffer++;
		indexLeft++;
	}
	while( indexRight <= right ){
		buffer[indexBuffer] = vec[indexRight];
		indexBuffer++;
		indexRight++;
	}
	for( int i=left; i<indexBuffer; i++){
		vec[i] = buffer[i];
	}
}

//add element at the end of container
void CSortedTrackInfo::addElement( CTrackInfo trackInfo ){
	vec.push_back(trackInfo);
}

//find an element with same title
bool CSortedTrackInfo::contains( const CTrackInfo trackInfo ){
	bool flag = false;
	if(!vec.empty()){
		mapp_it	iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			if((*iter).mTitle == trackInfo.mTitle ){
				return flag = true;
			}
		}
	}
	return flag;
}

const CTrackInfo& CSortedTrackInfo::getElement( const mapp_sz_type index ) const{
	return vec.at(index);
}

CTrackInfo& CSortedTrackInfo::getElement( const mapp_sz_type index ){
	return vec.at(index);
}

CTrackInfo& CSortedTrackInfo::getElement( const std::string& name){
	if(!vec.empty()){
		mapp_it	iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			if((*iter).mTitle == name){
				return (*iter);
			}
		}	
	}
	return (*vec.begin());
}

//removes an element
void CSortedTrackInfo::removeElement( const mapp_sz_type index ){
	if( index >= vec.size() ){
		//not such index
	}else{
		const mapp_it iter = vec.begin() + index;
		vec.erase(iter); 
	}
}

//delete all elements in container
void CSortedTrackInfo::clearElements( void ){

	if(!vec.empty()){
		/*mapp_it	iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			delete (*iter);
		}*/
		vec.clear();
	}
}

//is container empty
bool CSortedTrackInfo::isEmpty( void ) const{
	return vec.empty();
}

//size of mapping collection
const CSortedTrackInfo::mapp_sz_type CSortedTrackInfo::getSizeOfSortedMapping( void ) const {
	return vec.size();
}

//begin-iterator
CSortedTrackInfo::mapp_it CSortedTrackInfo::getBeginIterator( void ){
	return vec.begin();
}

//end-iterator
CSortedTrackInfo::mapp_it CSortedTrackInfo::getEndIterator( void ){
	return vec.end();
}

//const_begin-iterator
CSortedTrackInfo::mapp_const_it CSortedTrackInfo::getBeginIterator( void) const {
	return vec.begin();
}

//const_end-iterator
CSortedTrackInfo::mapp_const_it CSortedTrackInfo::getEndIterator( void ) const{
	return vec.end();
}