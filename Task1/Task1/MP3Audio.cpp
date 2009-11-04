#include "StdAfx.h"
#include "MP3Audio.h"
#include "ID3Utils.h"

MP3Audio* MP3Audio::read(std::string& file){

  // TODO check if file is an mp3

  //get a ID3Tag object
  ID3Utils utils(file);

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
  
  //Bitrate
  //comment - ID3FID_COMMENT
  //BPM - ID3FID_BPM

  return new MP3Audio(pFilePath, sTitle, sInterpret, sAlbum, sYear, pGenre, dFileSize, sTrackNum, pFilename);

}