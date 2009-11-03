#include "StdAfx.h"
#include "MP3Audio.h"
#include <id3/tag.h>
#include <iostream>
#include <sstream>


MP3Audio* MP3Audio::read(std::string& file){

  // TODO check if it's an mp3
  
  ID3_Tag tag(file.c_str());
  bool id3v2 = tag.HasV2Tag();
  bool id3v1 = tag.HasV1Tag();
  // if tag == NULL get new one


  //reading the title tag
  const char* ptitle = "";
  ID3_Frame* frame_title = tag.Find(ID3FID_TITLE);
  if(NULL != frame_title) {
    ptitle = frame_title->GetField(ID3FN_TEXT)->GetRawText();
  }
  
  //read artist
  std::string pinterpret = "";

  ID3_Frame* frame_artist = tag.Find(ID3FID_LEADARTIST);

  if(NULL != frame_artist){

	ID3_Field* myField = NULL;
	myField = frame_artist->GetField(ID3FN_TEXT);

	if(NULL != myField){

		enum ID3_FieldType eType = myField->GetType();

		if(eType == ID3FTY_TEXTSTRING){
			
			ID3_TextEnc ePreviousEncoding = myField->GetEncoding();
			myField->SetEncoding(ID3TE_ISO8859_1);
			size_t nTextSize = myField->Size();

				if ( nTextSize > 0 ) {
					char pszText[1024];
					size_t copiedText = myField->Get(pszText, nTextSize+1);
					if(nTextSize == copiedText){
						//convert char[] into std::string
						std::stringstream s;
						s << pszText;
						pinterpret = s.str();
					}else{
						pinterpret.erase();
					}
				}

			myField->SetEncoding(ePreviousEncoding);
		}else{
			//implement how to read int
		}
	}
  }	

  //read albumtitle
  std::string palbum = "";
  ID3_Frame* frame_album = tag.Find(ID3FID_ALBUM);
  if(NULL != frame_album){
	ID3_Field* myField = NULL;
	myField = frame_album->GetField(ID3FN_TEXT);
	if(NULL != myField){

		enum ID3_FieldType eType = myField->GetType();

		if(eType == ID3FTY_TEXTSTRING){
			
			ID3_TextEnc ePreviousEncoding = myField->GetEncoding();
			myField->SetEncoding(ID3TE_ISO8859_1);
			size_t nTextSize = myField->Size();

				if ( nTextSize > 0 ) {
					char pszText[1024];
					size_t copiedText = myField->Get(pszText, nTextSize+1);
					if(nTextSize == copiedText){
						//convert char[] into std::string
						std::stringstream s;
						s << pszText;
						palbum = s.str();
					}else{
						palbum.erase();
					}
				}

			myField->SetEncoding(ePreviousEncoding);
		}else{
			//implement how to read int
		}
	}
  }

  //year
  //comment
  //genre
  const char* pgenre = "";
  const char* pfilename = "";
  
  //MP3Audio* mp3 =   new MP3Audio(pfilename, ptitle, pinterpret, palbum, pgenre); //temporäres Objekt
 
  //return mp3;
  return new MP3Audio(pfilename, ptitle, pinterpret, palbum, pgenre);

}