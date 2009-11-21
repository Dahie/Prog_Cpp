#include "StdAfx.h"
#include "ID3Reader.h"
#include "ID3LibWrapper.h"

using namespace MP3;

CID3Reader::CID3Reader(void)
{
}

CID3Reader::~CID3Reader(void)
{
}

bool CID3Reader::isMP3File( const std::string& sFilePathName ) const {
	
	bool flag = false;
	const char* pFilePathName = sFilePathName.c_str();
	const char* fileEnd;
	std::string comp = "MP3", comp1 = "mp3";
	//get pointer on last character of filepath
	const char* pLastChar = pFilePathName + strlen(pFilePathName);
	
	while(--pLastChar > pFilePathName){
		if( *pLastChar == '.'){
			fileEnd = pLastChar + 1;
			break;
		}
	}
	if(fileEnd == comp || fileEnd == comp1){
		return flag = true;
	}

	return flag;
}

CMP3Audio* CID3Reader::readMP3Data( const std::string& sFilePath ){

  //create a ID3Tag object
  CID3LibWrapper* id3Lib = new CID3LibWrapper(sFilePath);
  if(!id3Lib){
	  System::Windows::Forms::MessageBox::Show("\nERROR: No memory access...\n\n\nID3Tag object was NOT created!\n\n","MP3 Tagger",
		  System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	  return NULL;
  }

  //title - ID3FID_TITLE
  std::string sTitle = "<no title>";
  id3Lib->getTitle(sTitle);
  
  //interpret - ID3FID_LEADARTIST
  std::string sInterpret = "<no artist>";
  id3Lib->getInterpret(sInterpret);
 
  //albumtitle - ID3FID_ALBUM
  std::string sAlbum = "<no album>";
  id3Lib->getAlbum(sAlbum);

  //year - ID3FID_YEAR
  std::string sYear = "";
  id3Lib->getYear(sYear);

  //tracknumber - ID3FID_TRACKNUM
  std::string sTrackNum = "";
  id3Lib->getTrackNumber(sTrackNum);
  
  //genre
  const char* pGenre = id3Lib->getGenre();

  //filename
  const char* pFilename = id3Lib->getFileName(sFilePath.c_str());
  
  //filesize in MegaByte
  double dFileSize = id3Lib->getFileSize();
  
  //comment - ID3FID_COMMENT
  std::string sComment = "<no comment>";
  id3Lib->getComment(sComment);

  //BPM - ID3FID_BPM
  std::string sBPM = "";
  id3Lib->getBPM(sBPM);

   //Bitrate in kb/s
  int iBitrate = id3Lib->getBitrate();

  //if size of File is NULL no tag was read in ID3Utils.cpp
  if(!dFileSize){
	System::Windows::Forms::MessageBox::Show("\nERROR: No memory access... ID3Tag was NOT read successfully!\n\n\nMP3 Info corrupted!!!!\n\n","MP3 Tagger",
		  System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	return NULL;
  }

  //delete ID3Utils pointer and object
  delete id3Lib;

  return new CMP3Audio(sFilePath, sTitle, sInterpret, sAlbum, sYear, pGenre, dFileSize, sTrackNum, pFilename, sComment, sBPM, iBitrate);
}
