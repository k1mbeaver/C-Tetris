#pragma once
#include "GameSystem01.h"
#include "TableBlock.h"

//게임 설명 클래스 
class GameStart {
private:
public:
	GameTable* way = 0;
	Menu* mway = 0;
	void HowtoGame()
	{
		way = new GameTable(TABLE_X, TABLE_Y); // 게임 판 그리기 객체 생성
		way->createBlock(); // 초기 블럭 생성
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
			if (fTime >= 1) { // 약 1초가 지나면
				way->MoveBlock(Down); // 블럭을 한칸 떨어 뜨림
				start = clock(); // 시간을 다시 잼
			}
			if (_kbhit()) {
				nSelect = _getch();
				if (nSelect == 224) {
					nSelect = _getch();
					switch (nSelect) {
					case Up:
						way->RotateBlock(); // 90도 회전
						break;
					case Down:
						way->MoveBlock(Down); // 아래로
						break;
					case Left:
						way->MoveBlock(Left); // 왼쪽으로
						break;
					case Right:
						way->MoveBlock(Right);  // 오른쪽으로
						break;
					default:
						break;
					}
				}
				else if (nSelect == Space) // 빨리 떨어뜨리기
				{
					way->HardDrop();
				}
			}
			if (way->isReachEnding()) return; // 종료 선에 닿으면 게임 종료
			if (nSelect == Enter) return;
			way->DeleteLinear();
			mway->GotoXY(0, 0);
			way->DrawGameTable();
		}
	}
	void returnGame() { // 게임 종료
		system("cls");
		mway->GotoXY(10, 10);
		cout << "GameOver!!";
		delete way;
	}
};
//게임도움말
