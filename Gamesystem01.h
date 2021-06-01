#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "End.h"
using namespace std;
#define TABLE_X 15
#define TABLE_Y 30
enum action {Up = 72, Down = 80, Left = 75, Right = 77, Space = 32, Enter = 13};


class Menu
{
public:
	void GotoXY(int nX, int nY);
	void CursorView(char show);
	int Main();
	void Select(int nSelect);
};

class GameTable 
{
private:
	int x;
	int y;
	vector<vector<int>> table; // ���̺� �� 0 = " ", 1 = "��", 2 = "��"
public:
	GameTable(int x, int y) // ��Ʈ���� �� ���� ����
	{
		x = TABLE_X;
		y = TABLE_Y;
		this->x = x;
		this->y = y;
		for (int i = 0; i < y; i++)
		{
			vector<int> temp; // ����ִ� vector temp�� ����
			for (int j = 0; j < x; j++)
			{
				temp.push_back(0); // temp�� ���������� �ڿ� 0�� �ִ´�.
			}
			table.push_back(temp); // table�� ���������� �ڿ� 0�� �ִ´�.
		}
		// ���� �ڸ� ���� ��ĥ
		for (int i = 0; i < x; i++)
		{
			table[0][i] = 1;
			table[y - 1][i] = 1;
		}
		for (int i = 1; i < y - 1; i++)
		{
			table[i][0] = 1;
			table[i][x - 1] = 1;
		}
	}
	void DrawGameTable();
};