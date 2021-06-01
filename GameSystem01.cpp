#include "Gamesystem01.h"

void Menu::GotoXY(int nX, int nY) {
	COORD CursorPosition = { nX, nY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Menu::CursorView(char show) // 커서 숨기기(0), 보이기(1)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int Menu::Main()
{
	CursorView(false);
	system(" mode  con lines=45   cols=150 | title Tetris Game");
	cout << "\n\n\n\n\n";
	cout << "\t\t" << "■■■■■■■■■     ■■■■■■■■■     ■■■■■■■■■     ■■■■■■■■■     ■■     ■■■■■■■■■" << endl;
	cout << "\t\t" << "        ■             ■                             ■             ■              ■     ■■     ■" << endl;
	cout << "\t\t" << "        ■             ■                             ■             ■            ■       ■■     ■" << endl;
	cout << "\t\t" << "        ■             ■■■■■■■■■             ■             ■■■■■■■         ■■     ■■■■■■■■■" << endl;
	cout << "\t\t" << "        ■             ■                             ■             ■           ■        ■■                     ■" << endl;
	cout << "\t\t" << "        ■             ■                             ■             ■             ■      ■■                     ■" << endl;
	cout << "\t\t" << "        ■             ■■■■■■■■■             ■             ■               ■    ■■     ■■■■■■■■■" << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t" << "                                                 메뉴에서 선택하여 주세요" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              1.           게임 시작" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              2.           게임 방법" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              3.             랭   킹" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              4.           게임 종료" << endl;
	cout << "\t\t" << "                                             ================================" << endl;

	int nSelect = 1;
	int nC = 1, nY = 16;

	while (nC != Enter)
	{
		if (_kbhit()) {
			nC = _getch();

			switch (nC) {
			case Up:
				if (nSelect > 1) {
					GotoXY(90, nY);
					cout << "     ";
					nY -= 2;
					GotoXY(92, nY);
					cout << "☜";
					nSelect--;
				}
				break;
			case Down:
				if (nSelect < 4) {
					GotoXY(90, nY);
					cout << "     ";
					nY += 2;
					GotoXY(92, nY);
					cout << "☜";
					nSelect++;
				}
				break;
			}
		}
	}
	return nSelect;
}

void Menu::Select(int nSelect)
{
	End myend;
	switch (nSelect)
	{
	case 1:
		//게임시작
		break;
	case 2:
		//게임설명
		break;
	case 3:
		//랭킹
		break;
	case 4:
		myend.PrintEnd();
		return;
	default:
		myend.PrintEnd();
		return;
	}
}

/*
void GameTable::DrawGameTable()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (table[i][j] == 1) cout << "▩";
			else cout << "  "; // 두칸
		}
		cout << "\n";
	}
}
*/