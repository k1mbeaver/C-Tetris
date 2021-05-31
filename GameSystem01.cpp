#include "Gamesystem01.h"

void Menu::GotoXY(int nX, int nY) {
	COORD CursorPosition = { nX, nY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

int Menu::Main()
{
	system(" mode  con lines=150   cols=150 ");
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