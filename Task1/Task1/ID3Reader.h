#pragma once
#if !defined(ID3LIBREADER_H)
#define ID3LIBREADER_H

#include "MP3Reader.h"

namespace MP3{

class CID3Reader : public IMP3Reader
{
	public:
		CID3Reader(void);
		~CID3Reader(void);

		bool isMP3File(const std::string& sFilePathName) const;
		CMP3Audio* readMP3Data(const std::string& sFilePath);

};//class CID3Reader

}
#endif //ID3LIBREADER_H