#pragma once

#include <string>

namespace MP3{

class MP3Audio
{
private:

	std::string filename;
	std::string title;
	std::string interpret;
	std::string album;
	std::string year;
	std::string genre;
	double fileSize;
	std::string trackNum;
	std::string filepath;
	

  

public:
  MP3Audio(
	  const char* pFilePath,
	  std::string sTitle, 
	  std::string sInterpret, 
	  std::string sAlbum,
	  std::string sYear,
	const char* pGenre,
	double dFileSize,
	std::string sTrackNum,
	const char* pFilename): 
      filepath(pFilePath), 
      title(sTitle),
      interpret(sInterpret), 
      album(sAlbum),
	  year(sYear),
      genre(pGenre) ,
	  fileSize(dFileSize),
	  trackNum(sTrackNum),
	  filename(pFilename){};
  ~MP3Audio(void) {};

  static MP3Audio* read(std::string& file);
  
  inline const char* getFileName() const { return this->filename.c_str(); }
  inline const char* getTitle() const { return this->title.c_str(); }
  inline const char* getArtist() const { return this->interpret.c_str(); }
  inline const char* getAlbum() const { return this->album.c_str(); }
  inline const char* getYear() const { return this->year.c_str(); }
  inline const char* getGenre() const { return this->genre.c_str(); }
  inline double getFileSize() const { return this->fileSize; }
  inline const char* getTrackNum() const { return this->trackNum.c_str(); }
  inline const char* getFilePath() const { return this->filepath.c_str(); }
   
 
   

};
}