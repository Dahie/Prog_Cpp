#include "StdAfx.h"
#include "MP3Audio.h"
#include "ID3Utils.h"

using namespace MP3;

CMP3Audio* CMP3Audio::read(std::string& file){

  // TODO check if file is an mp3

  //get a ID3Tag object
  CID3Utils utils(file);

  //title - ID3FID_TITLE
  std::string sTitle = "";
  utils.getTitle(sTitle);
  
  //interpret - ID3FID_LEADARTIST
  std::string sInterpret = "";
  utils.getInterpret(sInterpret);
 
  //albumtitle - ID3FID_ALBUM
  std::string sAlbum = "";
  utils.getAlbum(sAlbum);

  //year - ID3FID_YEAR
  std::string sYear = "";
  utils.getYear(sYear);

  //tracknumber - ID3FID_TRACKNUM
  std::string sTrackNum = "";
  utils.getTrackNumber(sTrackNum);
  
  //genre
  const char* pGenre = utils.getGenre();

  //pathname
  const char* pFilePath = utils.getFilePathName();

  //filename
  const char* pFilename = utils.getFileName(pFilePath);
  
  //filesize in MegaByte
  double dFileSize = utils.getFileSize();
  
  //comment - ID3FID_COMMENT
  std::string sComment = "";
  utils.getComment(sComment);

  //BPM - ID3FID_BPM
  std::string sBPM = "";
  utils.getBPM(sBPM);

   //Bitrate in kb/s
  int iBitrate = utils.getBitrate();

  

  return new CMP3Audio(pFilePath, sTitle, sInterpret, sAlbum, sYear, pGenre, dFileSize, sTrackNum, pFilename, sComment, sBPM, iBitrate);

}