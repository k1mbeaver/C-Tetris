#include "GameMenu.h"

void Qna::PrintMenu()
{
	int nCount = 0;
	int nC = 0;
	while (1)
	{
		system("cls");
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
		cout << endl;

		if (nCount == 0)
		{
			cout << "\t\t" << "                                        테트리스의 세계에 오신것을 환영합니다!!" << endl << endl;
			cout << "\t\t" << "                             1. 게임을 시작하게 되면 5가지의 블록들이 무작위로 소환 됩니다." << endl << endl;
			cout << "\t\t" << "                             2. 방향키 ←→를 사용하여 블록을 좌우로 움직일 수 있습니다." << endl << endl;
			cout << "\t\t" << "                             3. 방향키 ↓를 사용하여 블록을 아래로 내릴 수 있습니다. " << endl << endl;
			cout << "\t\t" << "                             4. 방향키 ↑를 사용하여 블록을 90도 회전 시킬 수 있습니다. " << endl << endl;
			cout << "\t\t" << "                             종료(E)                                                   =>Next(N)" << endl << endl;
			if (_kbhit()) {
				nC = _getch();

				if (nC == BExit || nC == SExit)
				{
					return;
				}

				else if (nC == BNext || nC == SNext)
				{
					nCount++;
					continue;
				}

				else
				{
					continue;
				}
			}
		}

		if (nCount == 1)
		{
			cout << "\t\t" << "                              5. 스페이스바를 누르면 블록을 빠르게 떨어뜨릴수 있습니다." << endl << endl;
			cout << "\t\t" << "                              6. 플레이 도중에 게임을 종료 하고 싶으시면 E를 눌러 나갈 수 있습니다." << endl << endl;
			cout << "\t\t" << "                              7. 블록을 바닥에 일렬로 완전히 두게 되면 사라지고 점수를 1000점을 얻습니다." << endl << endl;
			cout << "\t\t" << "                              8. 블록이 천장에 닿게 되면 게임오버 입니다." << endl << endl;
			cout << "\t\t" << "                              9. 점수가 신기록이 되면 최대 랭킹 10위까지 기록이 됩니다!!" << endl << endl;
			cout << "\t\t" << "                              <=Prev(P)                                               종료(E)" << endl << endl;
			if (_kbhit()) {
				nC = _getch();

				if (nC == BExit || nC == SExit)
				{
					return;
				}

				else if (nC == BPrev || nC == SPrev)
				{
					nCount--;
					continue;
				}

				else
				{
					continue;
				}
			}
		}
	}
	return;
}