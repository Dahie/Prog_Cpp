#pragma once
#if !defined(ID3READER_H)

#define ID3READER_H

#include "MP3Audio.h"
#include "MP3Reader.h"

class CID3Reader : public MP3::IMP3Reader
{
public:
	CID3Reader(void);
	~CID3Reader(void);

	bool isMP3File(const char* pFilePathName) const;
	MP3::CMP3Audio* read(std::string& sFilePath);
};
#endif //ID3READER_H