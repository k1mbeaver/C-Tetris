#pragma once
#include "GameSystem01.h"
class Block;

class GameTable
{
private:
	int nX;
	int nY;
	Block* blockObject;
	vector<vector<int>> table; // 블럭 정보 저장시 table[nY][nX]
public:
	GameTable(int nX, int nY) // 테트리스 판 뼈대 생성
	{
		blockObject = nullptr;
		this->nX = nX;
		this->nY = nY;
		for (int nIndex = 0; nIndex < nY; nIndex++)
		{
			vector<int> temp; // 비어있는 vector temp를 생성
			for (int nJndex = 0; nJndex < nX; nJndex++)
			{
				temp.push_back(0); // temp의 마지막원소 뒤에 0을 넣는다.
			}
			table.push_back(temp); // table의 마지막원소 뒤에 0을 넣는다.
		}
		// 가장 자리 뼈대 색칠


		for (int nIndex = 0; nIndex < nX; nIndex++)
		{
			table[0][nIndex] = 1;
			table[nY - 1][nIndex] = 1;
		}
		for (int nIndex = 1; nIndex < nY - 1; nIndex++)
		{
			table[nIndex][0] = 1;
			table[nIndex][nX - 1] = 1;
		}

		//밑바닥
		for (int nIndex = 1; nIndex < nX - 1; nIndex++)
		{
			table[nY - 1][nIndex] = 4; // 맨 밑 값 4
		}

		//게임 종료
		for (int nIndex = 1; nIndex < nX - 1; nIndex++)
		{
			table[END_Y][nIndex] = 5; // 게임 종료 선 5
		}
	}
	void DrawGameTable(); // 게임판 그리기
	void createBlock(); // 블럭 생성
	void MoveBlock(int nKey); // 블럭 움직이기
	void RotateBlock(); // 블럭 회전하기
	void BuildBlock(); // 블럭 쌓기
	void HardDrop(); // 빨리 떨어뜨리기(스페이스)
	int DeleteLinear();
	bool isReachEnding();
};

//블록 부모 클래스
class Block {
protected:
	int nShape[4][4][4]; // shape[rotate][y][x]
	int nX;
	int nY;
	int nRotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]로 4가지 상태 표현

public:
	int getShape(int nRotationCount, int nY, int nX);
	int getX();
	int getY();
	int getRotationCount();
	void down();
	void left();
	void right();
	void rotate();
	void setX(int nX);
	void setY(int nY);
	void setRotationCount(int nR);
	void setShape(int nR, int nY, int nX, int nValue);
	void up();
};

/*블럭, table 백업용 클래스*/
class backup {
public:
	/*블럭 백업*/
	static void updateBlock(Block* source, Block& backupBlock) {
		backupBlock.setX(source->getX()); // 블럭의 x좌표 백업
		backupBlock.setY(source->getY()); // 블럭의 y좌표 백업
		backupBlock.setRotationCount(source->getRotationCount()); // 블럭의 회전 상태 변수 백업
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					backupBlock.setShape(nIndex, nJndex, nKndex, source->getShape(nIndex, nJndex, nKndex)); // 블럭의 모양 백업
				}
			}
		}
	}
	/*table 백업*/
	static void updateTable(vector<vector<int> >& source, vector<vector<int> >& backupTable) {
		backupTable.resize(source.size(), vector<int>(source.size())); // 기존 table의 크기만큼 2차원 벡터 크기 할당
		copy(source.begin(), source.end(), backupTable.begin()); // 기존 table vector을 backupTable vector에 백업
	}
};

/*1번 블럭 클래스*/
class Block1 : public Block {
public:
	Block1() {
		nX = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock1[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};
/*2번 블럭 클래스*/
class Block2 : public Block {
public:
	Block2() {
		nX = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock2[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};
/*3번 블럭 클래스*/
class Block3 : public Block {
public:
	Block3() {
		nX = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock3[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};
/*4번 블럭 클래스*/
class Block4 : public Block {
public:
	Block4() {
		nX = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock4[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};
/*5번 블럭 클래스*/
class Block5 : public Block {
public:
	Block5() {
		nX = TABLE_X / 2 - 3; // 초기 생성 맨 위 중앙 쯤으로 맞춤
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock5[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};

