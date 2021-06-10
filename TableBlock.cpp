#include "TableBlock.h"

void GameTable::DrawGameTable()
{
    for (int nIndex = 0; nIndex < nY; nIndex++)
    {
        for (int nJndex = 0; nJndex < nX; nJndex++)
        {
            if (table[nIndex][nJndex] == 1 || table[nIndex][nJndex] == 4) cout << "▩"; // 겉
            else if (table[nIndex][nJndex] == 2 || table[nIndex][nJndex] == 3) cout << "■"; // 블럭
            else if (table[nIndex][nJndex] == 5) cout << "※"; // 종료 선
            else cout << "  "; // 두칸 띄우기
        }
        cout << "\n";
    }
}

/*블럭 생성*/
void GameTable::createBlock() {
    srand((unsigned int)time(NULL));
    int nSelect = rand() % 5 + 1; // 1 ~ 5 블럭
    if (nSelect == 1) blockObject = new Block1(); // 1번 블럭 생성
    else if (nSelect == 2)blockObject = new Block2(); // 2번 블럭 생성
    else if (nSelect == 3)blockObject = new Block3(); // 3번 블럭 생성
    else if (nSelect == 4)blockObject = new Block4(); // 4번 블럭 생성
    else if (nSelect == 5)blockObject = new Block5(); // 5번 블럭 생성

    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range 방지

            table[nY][nX] = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex);
            //블럭 객체를 테이블에 업데이트
        }
    }
}

/*블럭 이동*/
void GameTable::MoveBlock(int nKey) {
    /*백업*/
    Block backupBlock; // 백업용 Block 객체
    vector<vector<int> > backupTable; // 백업용 table vector
    backup::updateBlock(blockObject, backupBlock); // block 백업
    backup::updateTable(table, backupTable); // table 백업

    /*테이블에서 블럭 객체 지우기*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();
            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range 방지
            if (table[Y][X] == 2) { // 만약 블럭이면
                table[Y][X] = 0; // 테이블에서 지운다
            }
        }
    }

    /*블럭 이동*/
    if (nKey == Down) blockObject->down(); // 만약 인자로 들어온 key가 아랫 방향이면 블럭을 아래로 이동
    else if (nKey == Left) blockObject->left();  // 만약 인자로 들어온 key가 왼쪽 방향이면 블럭을 왼쪽으로 이동
    else if (nKey == Right) blockObject->right(); // 만약 인자로 들어온 key가 오른쪽 방향이면 블럭을 오른쪽으로 이동

    /*이동한 블럭 상태를 테이블에 갱신 or 취소*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();

            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range 방지

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //블럭 배열 값 얻기

            if (blockValue != 2) continue; // 블럭이 아니면 무시 (블럭은 2로 이루어져있음)

            if (table[Y][X] == 0) { // 빈공간이면 (갱신)
                table[Y][X] = blockValue; // 블럭을 이동시킴
            }
            else if (table[Y][X] == 1) { // 블럭이 양 옆 벽면에 닿으면 (취소)
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table 백업
                blockObject->setX(backupBlock.getX()); // 블럭 x 좌표 백업
                blockObject->setY(backupBlock.getY()); // 블럭 y 좌표 백업
                return; // 함수 종료
            }
            else if (table[Y][X] == 3) { // 이미 쌓여진 블럭과 접촉하면
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table 백업
                blockObject->setX(backupBlock.getX()); // 블럭 x 좌표 백업
                blockObject->setY(backupBlock.getY()); // 블럭 y 좌표 백업
                if (nKey == Down) { // 만약 아랫 방향일 경우에
                    BuildBlock(); // 블럭을 쌓고
                    createBlock(); // 새로운 블럭을 만듬
                }
                return; // 함수 종료
            }
            else if (table[Y][X] == 4) { //만약에 맨 밑바닥에 접촉했으면
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table 백업
                blockObject->setX(backupBlock.getX()); // 블럭 x 좌표 백업
                blockObject->setY(backupBlock.getY()); // 블럭 y 좌표 백업
                if (nKey == Down) { // 만약 아랫 방향일 경우에
                    BuildBlock(); // 블럭을 쌓고
                    createBlock(); // 새로운 블럭을 만듬
                }
                return; // 함수 종료
            }

        }
    }

}

/*블럭 회전*/
void GameTable::RotateBlock() {
    /*백업*/
    Block backupBlock; // 백업용 Block 객체
    vector<vector<int> > backupTable; // 백업용 table vector
    backup::updateBlock(blockObject, backupBlock); // block 백업
    backup::updateTable(table, backupTable); // table 백업

    /*테이블에서 블럭 객체 지우기*/
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range 방지

            if (table[nY][nX] == 2) { // 만약 블럭이면
                table[nY][nX] = 0; // 테이블에서 지운다
            }
        }
    }

    /*블럭 회전*/
    blockObject->rotate(); // 블럭을 회전

    /*회전한 블럭 상태를 테이블에 갱신 및 취소*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();

            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range 방지

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //블럭 배열 값 얻기

            if (blockValue != 2) continue; // 블럭이 아니면 무시 (블럭은 2로 이루어져있음)

            if (table[Y][X] == 0) { //빈공간인 경우에 이동한 블럭 정보를 테이블에 갱신
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
            }
            else if (table[Y][X] == 1 || table[Y][X] == 3 || table[Y][X] == 4) { // 블럭&블럭, 블럭&벽 닿을 시 취소
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table 백업
                blockObject->setRotationCount(backupBlock.getRotationCount()); // 회전하기 전 상태로 백업
                return; // 업데이트 취소
            }
        }
    }
}

/*블럭을 table에 쌓기*/
void GameTable::BuildBlock() {
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range 방지

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex); //블럭 배열 값 얻기
            if (blockValue != 2) continue; // 블럭이 아니면 무시 (블럭은 2로 이루어져있음)
            table[nY][nX] = 3;
        }
    }
}

/*스페이스바 누를 시 바로 떨어짐*/
void GameTable::HardDrop() {
    /*테이블에서 블럭 객체 지우기*/
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range 방지

            if (table[nY][nX] == 2) { // 만약 블럭이면
                table[nY][nX] = 0; // 테이블에서 지운다
            }
        }
    }
    while (true) { //바닥이나 블럭을 만날때까지 반복
        for (int nIndex = 0; nIndex < 4; nIndex++) {
            for (int nJndex = 0; nJndex < 4; nJndex++) {
                int nY = nJndex + blockObject->getY();
                int nX = nIndex + blockObject->getX();

                if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range 방지

                int blockValue = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex); //블럭 배열 값 얻기

                if (blockValue != 2) continue; // 블럭이 아니면 무시 (블럭은 2로 이루어져있음)

                if (table[nY][nX] == 3 || table[nY][nX] == 4) { // 블럭이나 벽을 만나면
                    blockObject->up(); // 한 칸 위로 올리고
                    BuildBlock(); // 블럭을 쌓고
                    createBlock(); // 새로운 블럭을 만듬
                    return; // 함수 종료
                }
            }
        }
        blockObject->down(); // 블럭을 한 칸 아래로 이동
    }
}

/*일직선 삭제*/
int GameTable::DeleteLinear() { // 여기에서 점수를 추가하는 방식으로 진행한다.
    for (int nY = END_Y + 1; nY < TABLE_Y - 1; nY++) {
        bool isLinear = true;
        for (int nX = 1; nX < TABLE_X - 1; nX++) {
            if (table[nY][nX] != 3) {
                isLinear = false;
            }
        }
        if (isLinear) {
            for (int nIndex = nY; nIndex > END_Y - 1; nIndex--) {
                for (int nJndex = 1; nJndex < TABLE_X - 1; nJndex++) {
                    table[nIndex][nJndex] = table[nIndex - 1][nJndex];
                }
            }
            return 1; // 점수 추가!
        }
    }
}

/*쌓은 블록이 게임 종료 선에 닿았는지 체크*/
bool GameTable::isReachEnding() {
    for (int nX = 1; nX < TABLE_X - 1; nX++) {
        if (table[END_Y][nX] == 3) return true;
    }
    return false;
}

int Block::getShape(int nRotationCount, int nY, int nX) {
    return nShape[nRotationCount][nY][nX];
}
int Block::getX() {
    return nX;
}
int Block::getY() {
    return nY;
}
int Block::getRotationCount() {
    return nRotationCount;
}
void Block::down() { // 블럭 한 칸 아래 이동
    nY++;
}
void Block::left() { // 블럭 한 칸 왼쪽 이동
    nX--;
}
void Block::right() { // 블럭 한 칸 오른쪽 이동
    nX++;
}
void Block::rotate() { // 블럭 회전
    nRotationCount = (nRotationCount + 1) % 4; // 0 , 1, 2 , 3 으로 회전 표현
}
void Block::setX(int nX) {
    this->nX = nX;
}
void Block::setY(int nY) {
    this->nY = nY;
}
void Block::setRotationCount(int nR) {
    this->nRotationCount = nR;
}
void Block::setShape(int nR, int nY, int nX, int nValue) {
    this->nShape[nR][nY][nX] = nValue;
}
void Block::up() { //hard drop 처리용 블럭 한 칸 위로 이동
    nY--;
}

