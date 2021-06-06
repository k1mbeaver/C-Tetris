#include "Gamesystem01.h"
#include "End.h"
#include "GameMenu.h"
#include "TableBlock.h"
#include "GameStart.h"

void Menu::GotoXY(int nX, int nY) {
	COORD CursorPosition = { nX, nY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Menu::CursorView(char show) // Ŀ�� �����(0), ���̱�(1)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Menu::textcolor(int nForeground)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nForeground);
}

int Menu::Main()
{
	CursorView(false);
	system(" mode  con lines=45   cols=150 | title Tetris Game");
	textcolor(10);
	cout << "\n\n\n\n\n";
	cout << "\t\t" << "����������     ����������     ����������     ����������     ���     ����������" << endl;
	cout << "\t\t" << "        ��             ��                             ��             ��              ��     ���     ��" << endl;
	cout << "\t\t" << "        ��             ��                             ��             ��            ��       ���     ��" << endl;
	cout << "\t\t" << "        ��             ����������             ��             ��������         ���     ����������" << endl;
	cout << "\t\t" << "        ��             ��                             ��             ��           ��        ���                     ��" << endl;
	cout << "\t\t" << "        ��             ��                             ��             ��             ��      ���                     ��" << endl;
	cout << "\t\t" << "        ��             ����������             ��             ��               ��    ���     ����������" << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t" << "                                                 �޴����� �����Ͽ� �ּ���" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              1.           ���� ����" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              2.           ���� ���" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              3.             ��   ŷ" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              4.           ���� ����" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	//���Ʒ� ����Ű, ���� �����̽� �߰�

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
					cout << "��";
					nSelect--;
				}
				break;
			case Down:
				if (nSelect < 4) {
					GotoXY(90, nY);
					cout << "     ";
					nY += 2;
					GotoXY(92, nY);
					cout << "��";
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
		int nCount = 0;
		nCount = Main();
		switch (nCount)
		{
		case 1:
			//���ӽ���
			system("cls");
			myStart.HowtoGame();
			continue;
		case 2:
			//���ӹ�� ������ �ϰ� ����
			myqna.PrintMenu();
			continue;
		case 3:
			//��ŷ
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
