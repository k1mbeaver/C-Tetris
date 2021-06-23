//C++를 이용하여 만드는 Tetris 게임입니다.
#include "GameSystem01.h"
#include "tinyxml.h"
#include "Rank.h"

int main()
{
	Rank gamerank;
	gamerank.makeRankxml();
	Menu game;
	game.textcolor(BLACK, WHITE);
	game.Select();

	cout << endl; return 0;
}