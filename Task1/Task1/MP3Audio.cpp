#include "StdAfx.h"
#include "MP3Audio.h"
#include <id3/tag.h>
#include <iostream>


MP3Audio* MP3Audio::read(std::string& file){

  // TODO check if it's an mp3
  
  ID3_Tag tag(file.c_str());


  const char* ptitle = 0;
  ID3_Frame* frame_title = tag.Find(ID3FID_TITLE);
  if(frame_title != 0) {
    ptitle = frame_title->GetField(ID3FN_TEXT)->GetRawText();
  }

  const char* palbum = "testalbum";
  const char* pfilename = 0;
  const char* pinterpret = 0; 
  const char* pgenre = 0;
  
  //MP3Audio mp3(pfilename, ptitle, pinterpret, palbum, pgenre); //temporäres Objekt
 
  //return &mp3;
  return new MP3Audio(pfilename, ptitle, pinterpret, palbum, pgenre);

}