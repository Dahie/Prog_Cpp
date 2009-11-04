#include "StdAfx.h"
#include "ID3Utils.h"
#include <sstream>
#include <id3/tag.h>
#include <id3/misc_support.h>

ID3Utils::ID3Utils(const std::string& sFileName):my_pTag(NULL),
	my_sFileName(sFileName)
{
}

ID3Utils::~ID3Utils(void)
{
}


void ID3Utils::readTag( void ){
	
	if( my_pTag == NULL){
		my_pTag = new ID3_Tag( my_sFileName.c_str() );
	}
}

bool ID3Utils::hasV1Tag(void) const{
	const_cast<ID3Utils*>(this)->readTag();
	return my_pTag->HasV1Tag();
}

bool ID3Utils::hasV2Tag(void) const{
	const_cast<ID3Utils*>(this)->readTag();
	return my_pTag->HasV2Tag();
}

const char* ID3Utils::getGenre(void) const {
	
	const_cast<ID3Utils*>(this)->readTag();
	size_t genreEnum = ID3_GetGenreNum(my_pTag);

	if(genreEnum <=ID3_NR_OF_V1_GENRES){
		return ID3_V1GENRE2DESCRIPTION(genreEnum);
	}else{
		//genreNumber is too large
		//return "";
	}

	return "";
}

const char* ID3Utils::getFilePathName(void) const{
	if(!my_sFileName.empty()){
		return my_sFileName.c_str();
	}
	return "";
}

const char* ID3Utils::getFileName( const char* pFilePathName )
{
	const char* pLastChar = pFilePathName + strlen(pFilePathName);

	while ( --pLastChar > pFilePathName ) {
		if ( *pLastChar == '/' || *pLastChar == '\\' ) {
			return pLastChar + 1;
		}
	}

	return pLastChar;
}

double ID3Utils::getFileSize(void) const{

	const_cast<ID3Utils*>(this)->readTag();
	size_t psize = my_pTag->GetFileSize();
	int size = static_cast<unsigned int>(psize);
	double dsize = System::Convert::ToDouble(size)/1024/1024;
	return dsize = ((int)(dsize*100+0.5))/100.0;

}

void ID3Utils::getTitle( std::string& sVal ) const {
	getFrameText( ID3FID_TITLE, sVal );
}

void ID3Utils::getInterpret( std::string& sVal ) const {
	getFrameText( ID3FID_LEADARTIST, sVal );
}

void ID3Utils::getAlbum(std::string& sVal ) const {
	getFrameText( ID3FID_ALBUM, sVal );
}

void ID3Utils::getYear(std::string& sVal ) const {
	getFrameText( ID3FID_YEAR, sVal );
}

void ID3Utils::getTrackNumber(std::string& sVal ) const {
	getFrameText( ID3FID_TRACKNUM, sVal );
}

void ID3Utils::getFrameText( enum ID3_FrameID eFrameId, std::string& sVal ) const{

	const_cast<ID3Utils*>(this)->readTag();
	ID3_Frame* pframe = my_pTag->Find(eFrameId);

	if(NULL != pframe){

		ID3_Field* pField = pframe->GetField(ID3FN_TEXT);
		
		if(NULL != pField){
			const_cast<ID3Utils*>(this)->getFieldText(pField, sVal);
		}
	}
}


void ID3Utils::getFieldText(ID3_Field *pField, std::string &sVal){

		enum ID3_FieldType eType = pField->GetType();

		if(eType == ID3FTY_TEXTSTRING){
			
			ID3_TextEnc ePreviousEncoding = pField->GetEncoding();
			pField->SetEncoding(ID3TE_ISO8859_1);
			size_t lenTextSize = pField->Size();

			if (lenTextSize > 0) {
				
				char copiedText[1024];
				size_t lenCopiedText = pField->Get(copiedText, lenTextSize+1);
				if(lenTextSize == lenCopiedText){
					//convert char[] into std::string
					std::stringstream s;
					s << copiedText;
					sVal = s.str();
				
				}else{

					sVal.erase();
					
				}
			}

			pField->SetEncoding(ePreviousEncoding);

		}else if (eType == ID3FTY_INTEGER){
			
			uint32 intVal = pField->Get();

			//convert uint32 in std::string
			std::stringstream ss;
			ss << intVal;
			ss >> sVal;

		}else{

			//open to do
		}
}

void testFrame(ID3_Frame* pFrame, ID3_Field* pField){

	//test-method for a frame, how many fields, which FieldId and which FieldType
	int fieldCount = pFrame->NumFields();
	uint32 content = 10;
	std::string pFieldType = "";

	ID3_Frame::Iterator* iter = pFrame->CreateIterator();
   
	while (NULL != (pField = iter->GetNext())){

		ID3_FieldID id = pField->GetID();
		enum ID3_FieldType eType = pField->GetType();

		if(eType == ID3FTY_TEXTSTRING){
			pFieldType = "isn string";
		}else if (eType == ID3FTY_INTEGER){
			pFieldType = "isn int";
			content = pField->Get();
		}else{pFieldType = "wat anders";}
	}

	//delete iter;
}
