#include "StdAfx.h"
#include "MP3ReaderFactory.h"

using namespace MP3;

CMP3ReaderFactory::CMP3ReaderFactory(void)
{
}

CMP3ReaderFactory::~CMP3ReaderFactory(void)
{
}

IMP3Reader* CMP3ReaderFactory::createInstance( void ){
	return new CID3Reader();
}
