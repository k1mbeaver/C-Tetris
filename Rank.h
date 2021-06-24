#pragma once
#include "GameSystem01.h"

class Rank {
public:
	char chName[10] = "\0";
	void makeRankxml();
	void makeRank(char* name, char* score);
	void readRank();
	char* makeName();
	int HighScore();
};