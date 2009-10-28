#pragma once

class MP3Audio
{
private:
  const char* filename;
  const char* title;
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

  static MP3Audio* read(const char* file);
};
