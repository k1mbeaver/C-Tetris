#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//게임 시작 클래스 
class GameStart {
private:
public:
	GameTable* way = 0;
	Menu* mway = 0;
	Menu selectdifficulty;
	void HowtoGame(int nDifficulty);
	int Difficulty();
	void GameEnd();
};
//게임도움말
