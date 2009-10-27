#pragma once

class MP3Audio
{
private:
  const char* file_name;
  const char* title;
  const char* interpret;
  const char* album;
  const char* genre;

  

public:
  MP3Audio(void);
  ~MP3Audio(void);
};
