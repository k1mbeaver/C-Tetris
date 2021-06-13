#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//게임 시작 클래스 
class GameStart {
private:
public:
	int nGameScore = 0;
	GameTable* way = 0;
	Menu mway;
	void HowtoGame(int nDifficulty);
	int Difficulty();
	void GameEnd();
};
//게임도움말
