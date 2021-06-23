#pragma once
#include "GameSystem01.h"

class Rank {
public:
	char chName[100] = "\0";
	void makeRankxml();
	void makeRank(char* name, char* score);
	void readRank();
	char* makeName();
};