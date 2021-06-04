#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//���� ���� Ŭ���� 
class GameStart {
private:
public:
	GameTable* way = 0;
	Menu* mway = 0;
	void HowtoGame()
	{
		way = new GameTable(TABLE_X, TABLE_Y); // ���� �� �׸��� ��ü ����
		way->createBlock(); // �ʱ� �� ����
		way->DrawGameTable();
		int nTimer = 0;
		clock_t start, end;
		start = clock();
		float fTime;
		while (true)
		{
			int nSelect = 0;
			end = clock();
			fTime = ((float)(end - start) / CLOCKS_PER_SEC);
			if (fTime >= 1) { // �� 1�ʰ� ������
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
			if (way->isReachEnding()) return; // ���� ���� ������ ���� ����
			if (nSelect == Enter) return;
			way->DeleteLinear();
			mway->GotoXY(0, 0);
			way->DrawGameTable();
		}
	}
	void returnGame() { // ���� ����
		system("cls");
		mway->GotoXY(10, 10);
		cout << "GameOver!!";
		delete way;
	}
};
//���ӵ���
