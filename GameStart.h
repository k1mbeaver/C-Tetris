#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"
#include "tinyxml.h"
#include "Rank.h"

//���� ���� Ŭ���� 
class GameStart {
private:
public:
	int nGameScore = 0;
	int nHighScore = 0;
	char chGameScore[100] = "\0";
	GameTable* way = 0;
	Menu mway;
	Rank myrank;
	TiXmlDocument finddoc;
	void HowtoGame(int nDifficulty);
	int Difficulty();
	int GameEnd();
	void RecordRank(int nScore);
};
//���ӵ���
