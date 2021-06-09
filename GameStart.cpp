//gamestart
#include "GameStart.h"

void GameStart::HowtoGame(int nDifficulty)
{
	way = new GameTable(TABLE_X, TABLE_Y); // ���� �� �׸��� ��ü ����
	way->createBlock(); // �ʱ� �� ����
	way->DrawGameTable();
	int nTimer = 0;
	float fSecond = 0;
	if (nDifficulty == 1)
	{
		fSecond = 3;
	}
	else if (nDifficulty == 2)
	{
		fSecond = 2;
	}
	else if (nDifficulty == 3)
	{
		fSecond = 1;
	}
	clock_t start, end;
	start = clock();
	float fTime;

	while (true)
	{
		int nSelect = 0;
		end = clock();
		fTime = ((float)(end - start) / CLOCKS_PER_SEC);
		if (fTime >= fSecond) { // �� 1�ʰ� ������
			way->MoveBlock(Down); // ���� ��ĭ ���� �߸�
			start = clock(); // �ð��� �ٽ� ��
		}
		if (_kbhit()) {
			nSelect = _getch();
			if (nSelect == 224) {
				nSelect = _getch();
				switch (nSelect) {
				case Up:
					way->RotateBlock(); // 90�� ȸ��
					break;
				case Down:
					way->MoveBlock(Down); // �Ʒ���
					break;
				case Left:
					way->MoveBlock(Left); // ��������
					break;
				case Right:
					way->MoveBlock(Right);  // ����������
					break;
				default:
					break;
				}
			}
			else if (nSelect == Space) // ���� ����߸���
			{
				way->HardDrop();
			}
		}
		if (way->isReachEnding())
		{

			return;
		}; // ���� ���� ������ ���� ����
		if (nSelect == Enter) return;
		way->DeleteLinear();
		mway->GotoXY(0, 0);
		way->DrawGameTable();
	}
}



int GameStart::Difficulty() { // ���̵�
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
	cout << "\t\t" << "                                                 ���̵��� �����Ͽ� �ּ���" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              1.             ����" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              2.             ����" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              3.            �����" << endl;
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
					selectdifficulty.GotoXY(90, nY);
					cout << "     ";
					nY -= 2;
					selectdifficulty.GotoXY(92, nY);
					cout << "��";
					nSelect--;
				}
				break;
			case Down:
				if (nSelect < 3) {
					selectdifficulty.GotoXY(90, nY);
					cout << "     ";
					nY += 2;
					selectdifficulty.GotoXY(92, nY);
					cout << "��";
					nSelect++;
				}
				break;
			}
		}
	}
	return nSelect;
}

void GameStart::GameEnd()
{
	int nC = 1;
	delete way;
	for (int nIndex = 5; nIndex > 0; nIndex--)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t" << "@@@@@@@@@@@               @@@@@          @@@@@     @@@@@       @@@@@@@@@@@" << endl;
		cout << "\t\t\t\t\t" << "@                       @       @        @    @   @    @       @" << endl;
		cout << "\t\t\t\t\t" << "@                      @         @       @     @ @     @" << endl;
		cout << "\t\t\t\t\t" << "@                     @           @      @      @      @       @" << endl;
		cout << "\t\t\t\t\t" << "@    @@@@@@          @@@@@@@@@@@@@@@     @             @       @@@@@@@@@@@" << endl;
		cout << "\t\t\t\t\t" << "@         @         @               @    @             @       @" << endl;
		cout << "\t\t\t\t\t" << "@         @        @                 @   @             @       @" << endl;
		cout << "\t\t\t\t\t" << "@         @       @                   @  @             @       @" << endl;
		cout << "\t\t\t\t\t" << "@@@@@@@@@@@      @                     @ @             @       @@@@@@@@@@@" << endl;
		cout << endl;
		cout << "\t\t\t\t\t" << "@@@@@@@@@@@      @                      @  @@@@@@@@@@@@@       @@@@@@@@@@@" << endl;
		cout << "\t\t\t\t\t" << "@         @        @                   @   @                   @        @" << endl;
		cout << "\t\t\t\t\t" << "@         @          @               @     @                   @       @" << endl;
		cout << "\t\t\t\t\t" << "@         @            @           @       @                   @      @" << endl;
		cout << "\t\t\t\t\t" << "@         @              @       @         @@@@@@@@@@@@@       @@@@@@@" << endl;
		cout << "\t\t\t\t\t" << "@         @                @   @           @                   @      @" << endl;
		cout << "\t\t\t\t\t" << "@         @                  @             @                   @       @" << endl;
		cout << "\t\t\t\t\t" << "@         @                                @                   @        @" << endl;
		cout << "\t\t\t\t\t" << "@@@@@@@@@@@                                @@@@@@@@@@@@@       @         @" << endl;
		Sleep(500);
		if (nIndex == 5)
		{
			selectdifficulty.textcolor(1);
		}
		else if (nIndex == 4)
		{
			selectdifficulty.textcolor(14);
		}
		else if (nIndex == 3)
		{
			selectdifficulty.textcolor(4);
		}
		else if (nIndex == 2)
		{
			selectdifficulty.textcolor(6);
		}
		else if (nIndex == 1)
		{
			selectdifficulty.textcolor(15);
		}
	}
	// 5�� ���� �ٲٰ� �� ���� ��� ���� ���� ��� �ϰ� ���� �� �Է¹����� �Ѿ�� �ڵ�
	cout << endl;
	cout << endl;
	cout << "\t\t" << "                                                           ����" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                                  ���⿡ ������ ����Ѵ�" << endl;
	/*
	if(������ �ְ� ���� �� ���)
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                             �١ڡ�  �ű�� ���� �Դϴ�!!! �١ڡ�" << endl;
	*/
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                                           Enter" << endl;
	cout << "\t\t" << "                                             ================================" << endl;

	while (nC != Enter)
	{
		if (_kbhit()) {
			nC = _getch();
		}
	}
}