#include "TableBlock.h"

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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
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
					nShape[nIndex][nJndex][nKndex] = nShape[nIndex][nJndex][nKndex]; // 블럭 객체 정보 저장
				}
			}
		}
	}
};
