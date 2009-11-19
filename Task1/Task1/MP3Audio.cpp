#include "StdAfx.h"
#include "MP3Audio.h"
//#include "ID3Utils.h"

using namespace MP3;


//bool CMP3Audio::isMP3File(const char* pFilePathName) {
//	
//	bool flag = false;
//	const char* fileEnd;
//	std::string comp = "MP3", comp1 = "mp3";
//	//get pointer on last character of filepath
//	const char* pLastChar = pFilePathName + strlen(pFilePathName);
//	
//	while(--pLastChar > pFilePathName){
//		if( *pLastChar == '.'){
//			fileEnd = pLastChar + 1;
//			break;
//		}
//	}
//	if(fileEnd == comp || fileEnd == comp1){
//		return flag = true;
//	}
//
//	return flag;
//}


//CMP3Audio* CMP3Audio::read(std::string& sFilePath){
//
//  //create a ID3Tag object
//  CID3Utils* utils = new CID3Utils(sFilePath);
//  if(!utils){
//	  System::Windows::Forms::MessageBox::Show("\nERROR: No memory access...\n\n\nID3Tag object was NOT created!\n\n","MP3 Tagger",
//		  System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
//	  return NULL;
//  }
//
//  //title - ID3FID_TITLE
//  std::string sTitle = "<no title>";
//  utils->getTitle(sTitle);
//  
//  //interpret - ID3FID_LEADARTIST
//  std::string sInterpret = "<no artist>";
//  utils->getInterpret(sInterpret);
// 
//  //albumtitle - ID3FID_ALBUM
//  std::string sAlbum = "<no album>";
//  utils->getAlbum(sAlbum);
//
//  //year - ID3FID_YEAR
//  std::string sYear = "";
//  utils->getYear(sYear);
//
//  //tracknumber - ID3FID_TRACKNUM
//  std::string sTrackNum = "";
//  utils->getTrackNumber(sTrackNum);
//  
//  //genre
//  const char* pGenre = utils->getGenre();
//
//  //filename
//  const char* pFilename = utils->getFileName(sFilePath.c_str());
//  
//  //filesize in MegaByte
//  double dFileSize = utils->getFileSize();
//  
//  //comment - ID3FID_COMMENT
//  std::string sComment = "<no comment>";
//  utils->getComment(sComment);
//
//  //BPM - ID3FID_BPM
//  std::string sBPM = "";
//  utils->getBPM(sBPM);
//
//   //Bitrate in kb/s
//  int iBitrate = utils->getBitrate();
//
//  //if size of File is NULL no tag was read in ID3Utils.cpp
//  if(!dFileSize){
//	System::Windows::Forms::MessageBox::Show("\nERROR: No memory access... ID3Tag was NOT read successfully!\n\n\nMP3 Info corrupted!!!!\n\n","MP3 Tagger",
//		  System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
//	return NULL;
//  }
//
//  //delete ID3Utils pointer and object
//  delete utils;
//
//  return new CMP3Audio(sFilePath, sTitle, sInterpret, sAlbum, sYear, pGenre, dFileSize, sTrackNum, pFilename, sComment, sBPM, iBitrate);
//}