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
		Sleep(500);
		if (nIndex == 5)
		{
			mymenu.textcolor(1);
		}
		else if (nIndex == 4)
		{
			mymenu.textcolor(14);
		}
		else if (nIndex == 3)
		{
			mymenu.textcolor(4);
		}
		else if (nIndex == 2)
		{
			mymenu.textcolor(6);
		}
		else if (nIndex == 1)
		{
			mymenu.textcolor(15);
		}
	}
}//종료