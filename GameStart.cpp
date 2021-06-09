//gamestart
#include "GameStart.h"

void GameStart::HowtoGame(int nDifficulty)
{
	way = new GameTable(TABLE_X, TABLE_Y); // 게임 판 그리기 객체 생성
	way->createBlock(); // 초기 블럭 생성
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
		if (fTime >= fSecond) { // 약 1초가 지나면
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
		if (way->isReachEnding())
		{

			return;
		}; // 종료 선에 닿으면 게임 종료
		if (nSelect == Enter) return;
		way->DeleteLinear();
		mway->GotoXY(0, 0);
		way->DrawGameTable();
	}
}



int GameStart::Difficulty() { // 난이도
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
	cout << "\t\t" << "                                                 난이도를 선택하여 주세요" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              1.             쉬움" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              2.             보통" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                              3.            어려움" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	//위아래 방향키, 선택 스페이스 추가

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
					cout << "☜";
					nSelect--;
				}
				break;
			case Down:
				if (nSelect < 3) {
					selectdifficulty.GotoXY(90, nY);
					cout << "     ";
					nY += 2;
					selectdifficulty.GotoXY(92, nY);
					cout << "☜";
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
	// 5번 색깔 바꾸고 그 다음 가운데 에서 점수 출력 하고 유지 후 입력받으면 넘어가게 코딩
	cout << endl;
	cout << endl;
	cout << "\t\t" << "                                                           점수" << endl;
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                                  여기에 점수를 출력한다" << endl;
	/*
	if(점수가 최고 점수 일 경우)
	cout << "\t\t" << "                                             ================================" << endl;
	cout << "\t\t" << "                                             ☆★☆  신기록 점수 입니다!!! ☆★☆" << endl;
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