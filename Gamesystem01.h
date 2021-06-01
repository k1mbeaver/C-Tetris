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
	vector<vector<int>> table; // 테이블 판 0 = " ", 1 = "▩", 2 = "■"
public:
	GameTable(int x, int y) // 테트리스 판 뼈대 생성
	{
		x = TABLE_X;
		y = TABLE_Y;
		this->x = x;
		this->y = y;
		for (int i = 0; i < y; i++)
		{
			vector<int> temp; // 비어있는 vector temp를 생성
			for (int j = 0; j < x; j++)
			{
				temp.push_back(0); // temp의 마지막원소 뒤에 0을 넣는다.
			}
			table.push_back(temp); // table의 마지막원소 뒤에 0을 넣는다.
		}
		// 가장 자리 뼈대 색칠
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