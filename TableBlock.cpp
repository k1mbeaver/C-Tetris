#include "TableBlock.h"

void GameTable::DrawGameTable()
{
    for (int nIndex = 0; nIndex < nY; nIndex++)
    {
        for (int nJndex = 0; nJndex < nX; nJndex++)
        {
            if (table[nIndex][nJndex] == 1 || table[nIndex][nJndex] == 4) cout << "��"; // ��
            else if (table[nIndex][nJndex] == 2 || table[nIndex][nJndex] == 3) cout << "��"; // ��
            else if (table[nIndex][nJndex] == 5) cout << "��"; // ���� ��
            else cout << "  "; // ��ĭ ����
        }
        cout << "\n";
    }
}

/*�� ����*/
void GameTable::createBlock() {
    srand((unsigned int)time(NULL));
    int nSelect = rand() % 5 + 1; // 1 ~ 5 ��
    if (nSelect == 1) blockObject = new Block1(); // 1�� �� ����
    else if (nSelect == 2)blockObject = new Block2(); // 2�� �� ����
    else if (nSelect == 3)blockObject = new Block3(); // 3�� �� ����
    else if (nSelect == 4)blockObject = new Block4(); // 4�� �� ����
    else if (nSelect == 5)blockObject = new Block5(); // 5�� �� ����

    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range ����

            table[nY][nX] = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex);
            //�� ��ü�� ���̺� ������Ʈ
        }
    }
}

/*�� �̵�*/
void GameTable::MoveBlock(int nKey) {
    /*���*/
    Block backupBlock; // ����� Block ��ü
    vector<vector<int> > backupTable; // ����� table vector
    backup::updateBlock(blockObject, backupBlock); // block ���
    backup::updateTable(table, backupTable); // table ���

    /*���̺��� �� ��ü �����*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();
            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range ����
            if (table[Y][X] == 2) { // ���� ���̸�
                table[Y][X] = 0; // ���̺��� �����
            }
        }
    }

    /*�� �̵�*/
    if (nKey == Down) blockObject->down(); // ���� ���ڷ� ���� key�� �Ʒ� �����̸� ���� �Ʒ��� �̵�
    else if (nKey == Left) blockObject->left();  // ���� ���ڷ� ���� key�� ���� �����̸� ���� �������� �̵�
    else if (nKey == Right) blockObject->right(); // ���� ���ڷ� ���� key�� ������ �����̸� ���� ���������� �̵�

    /*�̵��� �� ���¸� ���̺� ���� or ���*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();

            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range ����

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //�� �迭 �� ���

            if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)

            if (table[Y][X] == 0) { // ������̸� (����)
                table[Y][X] = blockValue; // ���� �̵���Ŵ
            }
            else if (table[Y][X] == 1) { // ���� �� �� ���鿡 ������ (���)
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                return; // �Լ� ����
            }
            else if (table[Y][X] == 3) { // �̹� �׿��� ���� �����ϸ�
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                if (nKey == Down) { // ���� �Ʒ� ������ ��쿡
                    BuildBlock(); // ���� �װ�
                    createBlock(); // ���ο� ���� ����
                }
                return; // �Լ� ����
            }
            else if (table[Y][X] == 4) { //���࿡ �� �عٴڿ� ����������
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                blockObject->setX(backupBlock.getX()); // �� x ��ǥ ���
                blockObject->setY(backupBlock.getY()); // �� y ��ǥ ���
                if (nKey == Down) { // ���� �Ʒ� ������ ��쿡
                    BuildBlock(); // ���� �װ�
                    createBlock(); // ���ο� ���� ����
                }
                return; // �Լ� ����
            }

        }
    }

}

/*�� ȸ��*/
void GameTable::RotateBlock() {
    /*���*/
    Block backupBlock; // ����� Block ��ü
    vector<vector<int> > backupTable; // ����� table vector
    backup::updateBlock(blockObject, backupBlock); // block ���
    backup::updateTable(table, backupTable); // table ���

    /*���̺��� �� ��ü �����*/
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range ����

            if (table[nY][nX] == 2) { // ���� ���̸�
                table[nY][nX] = 0; // ���̺��� �����
            }
        }
    }

    /*�� ȸ��*/
    blockObject->rotate(); // ���� ȸ��

    /*ȸ���� �� ���¸� ���̺� ���� �� ���*/
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int Y = j + blockObject->getY();
            int X = i + blockObject->getX();

            if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // array out of range ����

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //�� �迭 �� ���

            if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)

            if (table[Y][X] == 0) { //������� ��쿡 �̵��� �� ������ ���̺� ����
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
            }
            else if (table[Y][X] == 1 || table[Y][X] == 3 || table[Y][X] == 4) { // ��&��, ��&�� ���� �� ���
                copy(backupTable.begin(), backupTable.end(), table.begin()); // table ���
                blockObject->setRotationCount(backupBlock.getRotationCount()); // ȸ���ϱ� �� ���·� ���
                return; // ������Ʈ ���
            }
        }
    }
}

/*���� table�� �ױ�*/
void GameTable::BuildBlock() {
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range ����

            int blockValue = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex); //�� �迭 �� ���
            if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)
            table[nY][nX] = 3;
        }
    }
}

/*�����̽��� ���� �� �ٷ� ������*/
void GameTable::HardDrop() {
    /*���̺��� �� ��ü �����*/
    for (int nIndex = 0; nIndex < 4; nIndex++) {
        for (int nJndex = 0; nJndex < 4; nJndex++) {
            int nY = nJndex + blockObject->getY();
            int nX = nIndex + blockObject->getX();

            if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range ����

            if (table[nY][nX] == 2) { // ���� ���̸�
                table[nY][nX] = 0; // ���̺��� �����
            }
        }
    }
    while (true) { //�ٴ��̳� ���� ���������� �ݺ�
        for (int nIndex = 0; nIndex < 4; nIndex++) {
            for (int nJndex = 0; nJndex < 4; nJndex++) {
                int nY = nJndex + blockObject->getY();
                int nX = nIndex + blockObject->getX();

                if (nY < 0 || nX < 0 || nY >= TABLE_Y || nX >= TABLE_X) continue; // array out of range ����

                int blockValue = blockObject->getShape(blockObject->getRotationCount(), nIndex, nJndex); //�� �迭 �� ���

                if (blockValue != 2) continue; // ���� �ƴϸ� ���� (���� 2�� �̷��������)

                if (table[nY][nX] == 3 || table[nY][nX] == 4) { // ���̳� ���� ������
                    blockObject->up(); // �� ĭ ���� �ø���
                    BuildBlock(); // ���� �װ�
                    createBlock(); // ���ο� ���� ����
                    return; // �Լ� ����
                }
            }
        }
        blockObject->down(); // ���� �� ĭ �Ʒ��� �̵�
    }
}

/*������ ����*/
int GameTable::DeleteLinear() { // ���⿡�� ������ �߰��ϴ� ������� �����Ѵ�.
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
            return 1; // ���� �߰�!
        }
    }
}

/*���� ����� ���� ���� ���� ��Ҵ��� üũ*/
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
void Block::down() { // �� �� ĭ �Ʒ� �̵�
    nY++;
}
void Block::left() { // �� �� ĭ ���� �̵�
    nX--;
}
void Block::right() { // �� �� ĭ ������ �̵�
    nX++;
}
void Block::rotate() { // �� ȸ��
    nRotationCount = (nRotationCount + 1) % 4; // 0 , 1, 2 , 3 ���� ȸ�� ǥ��
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
void Block::up() { //hard drop ó���� �� �� ĭ ���� �̵�
    nY--;
}

