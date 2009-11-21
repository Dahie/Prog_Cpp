#include "StdAfx.h"
#include "ID3LibWrapper.h"
#include <sstream>
#include <id3/tag.h>
#include <id3/misc_support.h>

using namespace MP3;

CID3LibWrapper::CID3LibWrapper( const std::string& sFileName ):my_sFileName( sFileName ),
myTag( sFileName.c_str() )	
{
}

CID3LibWrapper::~CID3LibWrapper(void)
{	
}


bool CID3LibWrapper::hasV1Tag( void ) const{
	return myTag.HasV1Tag();
}

bool CID3LibWrapper::hasV2Tag( void ) const{
	return myTag.HasV2Tag();
}

const char* CID3LibWrapper::getGenre( void ) const {
	
	ID3_Tag* pTag = new ID3_Tag(this->my_sFileName.c_str());
	if(!pTag){ 
		System::Windows::Forms::MessageBox::Show("ERROR: no memory access... ID3Tag \"<genre>\" was not read... MP3 Info corrupted");
		return "ERROR: ID3Tag \"<genre>\" not available";
	}

	size_t genreEnum = ID3_GetGenreNum(pTag);
	if(genreEnum <=ID3_NR_OF_V1_GENRES){
		return ID3_V1GENRE2DESCRIPTION(genreEnum);
	}else{
		//genreNumber is too large
		return "<no genre>";
	}
	delete pTag;
}

const char* CID3LibWrapper::getFilePathName( void ) const{
	return my_sFileName.c_str();
}

const char* CID3LibWrapper::getFileName( const char* pFilePathName ){

	const char* pLastChar = pFilePathName + strlen(pFilePathName);

	while ( --pLastChar > pFilePathName ) {
		if ( *pLastChar == '/' || *pLastChar == '\\' ) {
			return pLastChar + 1;
		}
	}

	return pLastChar;
}

double CID3LibWrapper::getFileSize( void ) const{

	size_t psize = myTag.GetFileSize();
	int size = static_cast<unsigned int>(psize);
	double dsize = System::Convert::ToDouble(size)/1024/1024;

	return dsize = ((int)(dsize*100+0.5))/100.0;
}

int CID3LibWrapper::getBitrate( void ) const{

	const Mp3_Headerinfo* pHeader = myTag.GetMp3HeaderInfo();

	return (pHeader != NULL ? pHeader->bitrate : 0)/1000;
}

void CID3LibWrapper::getTitle( std::string& sVal ) const {
	getFrameText( ID3FID_TITLE, sVal );
}

void CID3LibWrapper::getInterpret( std::string& sVal ) const {
	getFrameText( ID3FID_LEADARTIST, sVal );
}

void CID3LibWrapper::getAlbum( std::string& sVal ) const {
	getFrameText( ID3FID_ALBUM, sVal );
}

void CID3LibWrapper::getYear( std::string& sVal ) const {
	getFrameText( ID3FID_YEAR, sVal );
}

void CID3LibWrapper::getTrackNumber( std::string& sVal ) const {
	getFrameText( ID3FID_TRACKNUM, sVal );
}

void CID3LibWrapper::getComment( std::string& sVal ) const {
	getFrameText( ID3FID_COMMENT, sVal );
}

void CID3LibWrapper::getBPM( std::string& sVal ) const {
	getFrameText( ID3FID_BPM, sVal );
}

void CID3LibWrapper::getFrameText( enum ID3_FrameID eFrameId, std::string& sVal ) const{

	ID3_Frame* pframe = myTag.Find(eFrameId);

	if(NULL != pframe){

		ID3_Field* pField = pframe->GetField(ID3FN_TEXT);
		
		if(NULL != pField){
			const_cast<CID3LibWrapper*>(this)->getFieldText(pField, sVal);
			//testFrame(pframe, pField);
		}
	}
}


void CID3LibWrapper::getFieldText( ID3_Field *pField, std::string &sVal ){

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
	
				}else{ sVal.erase(); }
			}

			pField->SetEncoding(ePreviousEncoding);

		}else if (eType == ID3FTY_INTEGER){
			
			uint32 intVal = pField->Get();

			//convert uint32 in std::string
			std::stringstream ss;
			ss << intVal;
			ss >> sVal;

		}else{ /*TODO if other FIELDTYPES are needed*/ }
}

//test-method for a frame, how many fields, which FieldId and which FieldType
//Condition pFrame and pField are not NULL
void CID3LibWrapper::testFrame( ID3_Frame* pFrame, ID3_Field* pField ) const {

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
		}else{ pFieldType = "wat anders"; }

		ID3_TextEnc ePreviousEncoding = pField->GetEncoding();
	}
	delete iter;
}


