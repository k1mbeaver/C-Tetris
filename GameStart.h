#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//���� ���� Ŭ���� 
class GameStart {
private:
public:
	int nGameScore = 0;
	GameTable* way = 0;
	Menu* mway = 0;
	Menu selectdifficulty;
	void HowtoGame(int nDifficulty);
	int Difficulty();
	void GameEnd();
};
//���ӵ���
