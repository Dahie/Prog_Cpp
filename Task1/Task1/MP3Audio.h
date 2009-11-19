#pragma once
#if !defined(MP3AUDIO_H)

#define MP3AUDIO_H

#include <string>

namespace MP3{

class CMP3Audio
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
	std::string comment;
	std::string bpm;
	int bitrate;
	
public:
  CMP3Audio(
	  std::string sFilePath,
	  std::string sTitle, 
	  std::string sInterpret, 
	  std::string sAlbum,
	  std::string sYear,
	  const char* pGenre,
	  double dFileSize,
	  std::string sTrackNum,
	  const char* pFilename,
	  std::string sComment,
	  std::string sBPM,
	  int iBitrate):
		  filepath(sFilePath),
		  title(sTitle),
		  interpret(sInterpret), 
		  album(sAlbum),
		  year(sYear),
		  genre(pGenre) ,
		  fileSize(dFileSize),
		  trackNum(sTrackNum),
		  filename(pFilename),
		  comment(sComment),
		  bpm(sBPM),
		  bitrate(iBitrate){};

  ~CMP3Audio(void){};

  //static CMP3Audio* read(std::string& file);
  //static bool isMP3File(const char* pFilePathName);
  
  //getter
  inline const char* getFileName() const { return this->filename.c_str(); }
  inline const char* getTitle() const { return this->title.c_str(); }
  inline const char* getArtist() const { return this->interpret.c_str(); }
  inline const char* getAlbum() const { return this->album.c_str(); }
  inline const char* getYear() const { return this->year.c_str(); }
  inline const char* getGenre() const { return this->genre.c_str(); }
  inline double getFileSize() const { return this->fileSize; }
  inline const char* getTrackNum() const { return this->trackNum.c_str(); }
  inline const char* getFilePath() const { return this->filepath.c_str(); }
  inline const char* getComment() const { return this->comment.c_str(); }
  inline const char* getBPM() const { return this->bpm.c_str(); }
  inline int getBitrate() const { return this->bitrate; }
   
};//class CMP3Audio
}
#endif //MP3AUDIO_H