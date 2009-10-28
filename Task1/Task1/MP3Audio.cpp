#include "StdAfx.h"
#include "MP3Audio.h"
#include <id3/tag.h>


MP3Audio* MP3Audio::read(const char* file){

  ID3_Tag tag(file);

  const char* ptitle;
  ID3_Frame* frame_title = tag.Find(ID3FID_TITLE);
  if(frame_title != 0) {
   ptitle = frame_title->GetField(ID3FN_TEXT)->GetRawText();
  }

 const char* palbum;
  const char* pfilename;
  const char* pinterpret; 
  const char* pgenre;

  MP3Audio mp3(pfilename, ptitle, pinterpret, palbum, pgenre);

  return &mp3;

}