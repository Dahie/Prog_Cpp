#pragma once

#include <string>

class MP3Audio
{
private:
  const char* filename;
  std::string title;
  const char* interpret;
  const char* album;
  const char* genre;

  

public:
  MP3Audio(const char* pfilename, 
	  const char* ptitle, 
    const char* pinterpret, 
    const char* palbum,
    const char* pgenre): 
      filename(pfilename), 
      title(ptitle),
      interpret(pinterpret), 
      album(palbum),
      genre(pgenre) {};
  ~MP3Audio(void) {};

  static MP3Audio* read(std::string& file);
  
  inline std::string getTitle() const { return this->title; }

};
