#include "End.h"

void End::PrintEnd()
{
	for (int nIndex = 5; nIndex > 0; nIndex--)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t" << "■■■■■■■■■■          ■              ■          ■■■■■■■■■■■               ■■     ■■" << endl;
		cout << "\t\t" << "■                ■            ■          ■            ■                                   ■■     ■■" << endl;
		cout << "\t\t" << "■            ■■                ■      ■              ■                                   ■■     ■■" << endl;
		cout << "\t\t" << "■■■■■■■                      ■  ■                ■■■■■■■■■■■               ■■     ■■" << endl;
		cout << "\t\t" << "■            ■■                    ■                  ■                                   ■■     ■■" << endl;
		cout << "\t\t" << "■                ■                  ■                  ■                                   ■■     ■■" << endl;
		cout << "\t\t" << "■■■■■■■■■■                  ■                  ■■■■■■■■■■■" << endl;
		cout << endl << endl;
		cout << "\t\t" << "                           플 레 이 해 주 셔 서 감 사 합 니 다 !!!!                            ■■     ■■" << endl;
		Sleep(300);
		if (nIndex == 5)
		{
			color.textcolor(BLUE, WHITE);
		}
		else if (nIndex == 4)
		{
			color.textcolor(RED, WHITE);
		}
		else if (nIndex == 3)
		{
			color.textcolor(GREEN, WHITE);
		}
		else if (nIndex == 2)
		{
			color.textcolor(BROWN, WHITE);
		}
		else if (nIndex == 1)
		{
			color.textcolor(BLACK, WHITE);
		}
	}
}//종료