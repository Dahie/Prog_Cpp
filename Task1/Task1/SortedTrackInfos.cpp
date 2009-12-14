#include "StdAfx.h"
#include "SortedTrackInfos.h"

CSortedTrackInfos::CSortedTrackInfos(void){
}

CSortedTrackInfos::~CSortedTrackInfos(void){
}

//sort elements in list
void CSortedTrackInfos::sortElements( void ){
	int size = this->getSizeOfSortedMapping()-1;
	this->mergeSort(this->vec, 0, size);
}

int CSortedTrackInfos::mergeSort( mapp_cont& vec, int left, int right ){
	int mid;
	if( left < right ){
		mid = ( left+right )/2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid+1, right);
		merge(vec, left, right, mid);
	}
	return(0);
}

void CSortedTrackInfos::merge( mapp_cont& vec, int left, int right, int mid ){

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
void CSortedTrackInfos::addElement( CTrackInfo trackInfo ){
	vec.push_back(trackInfo);
}

//find an element with same title
bool CSortedTrackInfos::contains( const CTrackInfo trackInfo ){
	bool flag = false;
	if(!vec.empty()){
		trackInfos_it iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			if((*iter).mTitle == trackInfo.mTitle ){
				return flag = true;
			}
		}
	}
	return flag;
}

const CTrackInfo& CSortedTrackInfos::getElement( const trackInfos_sz_type index ) const{
	return vec.at(index);
}

CTrackInfo& CSortedTrackInfos::getElement( const trackInfos_sz_type index ){
	return vec.at(index);
}

CTrackInfo& CSortedTrackInfos::getElement( const std::string& name){
	if(!vec.empty()){
		trackInfos_it	iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			if((*iter).mTitle == name){
				return (*iter);
			}
		}	
	}
	return (*vec.begin());
}

//removes an element
void CSortedTrackInfos::removeElement( const trackInfos_sz_type index ){
	if( index >= vec.size() ){
		//not such index
	}else{
		const trackInfos_it iter = vec.begin() + index;
		vec.erase(iter); 
	}
}

void CSortedTrackInfos::removeElement( const std::string& name ){
	if(!vec.empty()){
		trackInfos_it iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			if((*iter).mTitle == name){
				vec.erase(iter);
				return;
			}
		}	
	}		 
}

//delete all elements in container
void CSortedTrackInfos::clearElements( void ){

	if(!vec.empty()){
		/*mapp_it	iter;
		for ( iter = vec.begin(); iter != vec.end(); ++iter ){
			delete (*iter);
		}*/
		vec.clear();
	}
}

//is container empty
bool CSortedTrackInfos::isEmpty( void ) const{
	return vec.empty();
}

//size of mapping collection
const CSortedTrackInfos::trackInfos_sz_type CSortedTrackInfos::getSizeOfSortedMapping( void ) const {
	return vec.size();
}

//begin-iterator
CSortedTrackInfos::trackInfos_it CSortedTrackInfos::getBeginIterator( void ){
	return vec.begin();
}

//end-iterator
CSortedTrackInfos::trackInfos_it CSortedTrackInfos::getEndIterator( void ){
	return vec.end();
}

//const_begin-iterator
CSortedTrackInfos::trackInfos_const_it CSortedTrackInfos::getBeginIterator( void) const {
	return vec.begin();
}

//const_end-iterator
CSortedTrackInfos::trackInfos_const_it CSortedTrackInfos::getEndIterator( void ) const{
	return vec.end();
}