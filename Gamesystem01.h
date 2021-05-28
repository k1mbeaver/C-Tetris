#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
enum action {Up = 72, Down = 80, Left = 75, Right = 77, Space = 32, Enter = 13};

class Menu
{
public:
	void GotoXY(int nX, int nY) {
		COORD CursorPosition = { nX, nY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
	}
	int Main() 
	{
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
};