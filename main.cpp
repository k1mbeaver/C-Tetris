//C++�� �̿��Ͽ� ����� Tetris �����Դϴ�.
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