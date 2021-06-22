#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"
#include "tinyxml.h"
#include "Rank.h"

//게임 시작 클래스 
class GameStart {
private:
public:
	int nGameScore = 0;
	char chGameScore[255] = "\0";
	GameTable* way = 0;
	Menu mway;
	Rank myrank;
	TiXmlDocument finddoc;
	void HowtoGame(int nDifficulty);
	int Difficulty();
	char* GameEnd();
	void RecordRank(char* chGameScore);
};
//게임도움말
