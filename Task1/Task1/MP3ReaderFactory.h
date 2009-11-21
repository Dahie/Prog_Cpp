#pragma once
#if !defined(MP3READERFACTORY_H)
#define MP3READERFACTORY_H

#include "ID3Reader.h"

namespace MP3{

class CMP3ReaderFactory
{
private:
	CMP3ReaderFactory(void);
	~CMP3ReaderFactory(void);
public:
	static IMP3Reader* createInstance( void );

};//class CMP3ReaderFactory

}
#endif //MP3READERFACTORY_H
