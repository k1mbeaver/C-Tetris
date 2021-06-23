#include "Gamesystem01.h"
#include "End.h"
#include "GameMenu.h"
#include "TableBlock.h"
#include "GameStart.h"
#define SIZE 100

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
	//위아래 방향키, 선택 스페이스 추가

	int nSelect = 1;
	int nC = 1, nY = 16;

	while (nC != Space)
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

void Menu::Select()
{
	End myend;
	GameTable myTable(TABLE_X, TABLE_Y);
	Qna myqna;
	GameStart myStart;

	while (1)
	{
		int nSystemScore = 0;
		int nDifficult = 0;
		int nCount = 0;
		nCount = Main();
		switch (nCount)
		{
		case 1:
			//게임시작
			nDifficult = myStart.Difficulty();
			system("cls");
			myStart.HowtoGame(nDifficult);
			nSystemScore = myStart.GameEnd();
			myStart.RecordRank(nSystemScore);
			continue;
		case 2:
			//게임방법 디자인 하고 구현
			myqna.PrintMenu();
			continue;
		case 3:
			//랭킹
			continue;
		case 4:
			myend.PrintEnd();
			return;
		default:
			myend.PrintEnd();
			return;
		}
	}
}

void Menu::textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

