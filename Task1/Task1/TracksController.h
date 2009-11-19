#pragma once
#if !defined(TRACKSCONTROLLER_H)
#define TRACKSCONTROLLER_H
#include "ID3Reader.h"
#include "MP3Audio.h"
#include "Tracks.h"
#include "SortedTracks.h"

enum Response{
	NO_MP3_FILE, NOT_READ, OK, ALREADY_OPENED
};

class CTracksController
{
	private:
		MP3::CTracks* tracks;
		MP3::CSortedTracks* sortedTracks;

public:
	CTracksController(void);
	~CTracksController(void);

	Response addFile(std::string& filePath);
};

#endif //TRACKSCONTROLLER_H
