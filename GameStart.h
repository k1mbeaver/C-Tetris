#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//���� ���� Ŭ���� 
class GameStart {
private:
public:
	GameTable* way = 0;
	Menu* mway = 0;
	Menu selectdifficulty;
	void HowtoGame(int nDifficulty);
	void returnGame(); // ���� ����
	int Difficulty();
};
//���ӵ���
