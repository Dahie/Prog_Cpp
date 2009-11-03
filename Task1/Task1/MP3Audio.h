#pragma once

#include <string>

class MP3Audio
{
private:
	std::string filename;
  std::string title;
  std::string interpret;
  std::string album;
  std::string genre;

  

public:
  MP3Audio(const char* pfilename, 
	  const char* ptitle, 
	  std::string pinterpret, 
	  std::string palbum,
    const char* pgenre): 
      filename(pfilename), 
      title(ptitle),
      interpret(pinterpret), 
      album(palbum),
      genre(pgenre) {};
  ~MP3Audio(void) {};

  static MP3Audio* read(std::string& file);
  
  inline const char* getTitle() const { return this->title.c_str(); }
  inline const char* getAlbum() const { return this->album.c_str(); }
   inline const char* getArtist() const { return this->interpret.c_str(); }
   inline const char* getGenre() const { return this->genre.c_str(); }

};
