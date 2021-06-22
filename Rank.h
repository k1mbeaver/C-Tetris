#pragma once
#include "GameSystem01.h"

class Rank {
public:
	char chName = NULL;
	void makeRankxml(char*  name, char* score);
	void makeRank(char* name, char* score);
	void readRank();
	char makeName();
};