#include "TableBlock.h"

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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // �� ��ü ���� ����
				}
			}
		}
	}
};
