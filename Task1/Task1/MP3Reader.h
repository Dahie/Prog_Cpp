#pragma once
#ifndef MP3READER_H
#define MP3READER_H

#include "MP3Audio.h"

namespace MP3{

class IMP3Reader
{
	public:
		IMP3Reader(void);
		virtual ~IMP3Reader(void);

		virtual bool isMP3File(const std::string& sFilePathName) const = 0;
		virtual CMP3Audio* readMP3Data(const std::string& sFilePath) = 0;

};//abstract class IMP3Reader

}
#endif //MP3READER_H