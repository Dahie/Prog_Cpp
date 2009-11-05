#pragma once

#include <id3/tag.h>

namespace MP3{

class CID3Utils
{
	ID3_Tag* my_pTag;
	std::string my_sFileName;

public:

	CID3Utils(const std::string& sFileName);
	~CID3Utils(void);

	void getFrameText(enum ID3_FrameID eFrameId, std::string& sVal) const;
	void getFieldText(ID3_Field* pField, std::string& sVal);
	void readTag( void );

	void getTitle(std::string& sValue) const;
	void getInterpret(std::string& sValue) const;
	void getAlbum(std::string& sValue) const;
	void getYear(std::string& sValue) const;
	void getTrackNumber(std::string& sValue) const;
	const char* getGenre(void) const;
	const char* getFilePathName( void ) const;
	static const char* getFileName( const char* pszFileName );
	//int getBitrate(void) const;
	double getFileSize(void) const;
	void getComment(std::string& sValue) const;
	void getBPM(std::string& sValue) const;
	bool hasV1Tag(void) const;
	bool hasV2Tag(void) const;

	//only for test issues
	void testFrame(ID3_Frame* pFrame, ID3_Field* pField);

};//class CID3Utils

}
