#pragma once
#include "GameSystem01.h"
class Block;

class GameTable
{
private:
	int nX;
	int nY;
	Block* blockObject;
	vector<vector<int>> table; // �� ���� ����� table[nY][nX]
public:
	GameTable(int nX, int nY) // ��Ʈ���� �� ���� ����
	{
		blockObject = nullptr;
		this->nX = nX;
		this->nY = nY;
		for (int nIndex = 0; nIndex < nY; nIndex++)
		{
			vector<int> temp; // ����ִ� vector temp�� ����
			for (int nJndex = 0; nJndex < nX; nJndex++)
			{
				temp.push_back(0); // temp�� ���������� �ڿ� 0�� �ִ´�.
			}
			table.push_back(temp); // table�� ���������� �ڿ� 0�� �ִ´�.
		}
		// ���� �ڸ� ���� ��ĥ


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

		//�عٴ�
		for (int nIndex = 1; nIndex < nX - 1; nIndex++)
		{
			table[nY - 1][nIndex] = 4; // �� �� �� 4
		}

		//���� ����
		for (int nIndex = 1; nIndex < nX - 1; nIndex++)
		{
			table[END_Y][nIndex] = 5; // ���� ���� �� 5
		}
	}
	void DrawGameTable(); // ������ �׸���
	void createBlock(); // �� ����
	void MoveBlock(int nKey); // �� �����̱�
	void RotateBlock(); // �� ȸ���ϱ�
	void BuildBlock(); // �� �ױ�
	void HardDrop(); // ���� ����߸���(�����̽�)
	int DeleteLinear();
	bool isReachEnding();
};

//��� �θ� Ŭ����
class Block {
protected:
	int nShape[4][4][4]; // shape[rotate][y][x]
	int nX;
	int nY;
	int nRotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]�� 4���� ���� ǥ��

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

/*��, table ����� Ŭ����*/
class backup {
public:
	/*�� ���*/
	static void updateBlock(Block* source, Block& backupBlock) {
		backupBlock.setX(source->getX()); // ���� x��ǥ ���
		backupBlock.setY(source->getY()); // ���� y��ǥ ���
		backupBlock.setRotationCount(source->getRotationCount()); // ���� ȸ�� ���� ���� ���
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					backupBlock.setShape(nIndex, nJndex, nKndex, source->getShape(nIndex, nJndex, nKndex)); // ���� ��� ���
				}
			}
		}
	}
	/*table ���*/
	static void updateTable(vector<vector<int> >& source, vector<vector<int> >& backupTable) {
		backupTable.resize(source.size(), vector<int>(source.size())); // ���� table�� ũ�⸸ŭ 2���� ���� ũ�� �Ҵ�
		copy(source.begin(), source.end(), backupTable.begin()); // ���� table vector�� backupTable vector�� ���
	}
};

/*1�� �� Ŭ����*/
class Block1 : public Block {
public:
	Block1() {
		nX = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock1[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};
/*2�� �� Ŭ����*/
class Block2 : public Block {
public:
	Block2() {
		nX = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock2[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};
/*3�� �� Ŭ����*/
class Block3 : public Block {
public:
	Block3() {
		nX = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock3[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};
/*4�� �� Ŭ����*/
class Block4 : public Block {
public:
	Block4() {
		nX = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock4[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};
/*5�� �� Ŭ����*/
class Block5 : public Block {
public:
	Block5() {
		nX = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
		nY = 1;
		nRotationCount = 0;
		for (int nIndex = 0; nIndex < 4; nIndex++) {
			for (int nJndex = 0; nJndex < 4; nJndex++) {
				for (int nKndex = 0; nKndex < 4; nKndex++) {
					nShape[nIndex][nJndex][nKndex] = nBlock5[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};

