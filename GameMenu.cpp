#include "GameMenu.h"

void Qna::PrintMenu()
{
	int nCount = 0;
	int nC = 0;
	while (1)
	{
		system("cls");
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
		cout << endl;

		if (nCount == 0)
		{
			cout << "\t\t" << "                                        ��Ʈ������ ���迡 ���Ű��� ȯ���մϴ�!!" << endl << endl;
			cout << "\t\t" << "                             1. ������ �����ϰ� �Ǹ� 5������ ��ϵ��� �������� ��ȯ �˴ϴ�." << endl << endl;
			cout << "\t\t" << "                             2. ����Ű ��渦 ����Ͽ� ����� �¿�� ������ �� �ֽ��ϴ�." << endl << endl;
			cout << "\t\t" << "                             3. ����Ű �鸦 ����Ͽ� ����� �Ʒ��� ���� �� �ֽ��ϴ�. " << endl << endl;
			cout << "\t\t" << "                             4. ����Ű �踦 ����Ͽ� ����� 90�� ȸ�� ��ų �� �ֽ��ϴ�. " << endl << endl;
			cout << "\t\t" << "                             ����(E)                                                   =>Next(N)" << endl << endl;
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
			cout << "\t\t" << "                              5. �����̽��ٸ� ������ ����� ������ ����߸��� �ֽ��ϴ�." << endl << endl;
			cout << "\t\t" << "                              6. �÷��� ���߿� ������ ���� �ϰ� �����ø� E�� ���� ���� �� �ֽ��ϴ�." << endl << endl;
			cout << "\t\t" << "                              7. ����� �ٴڿ� �Ϸķ� ������ �ΰ� �Ǹ� ������� ������ 1000���� ����ϴ�." << endl << endl;
			cout << "\t\t" << "                              8. ����� õ�忡 ��� �Ǹ� ���ӿ��� �Դϴ�." << endl << endl;
			cout << "\t\t" << "                              9. ������ �ű���� �Ǹ� �ִ� ��ŷ 10������ ����� �˴ϴ�!!" << endl << endl;
			cout << "\t\t" << "                              <=Prev(P)                                               ����(E)" << endl << endl;
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