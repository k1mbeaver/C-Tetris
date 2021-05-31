#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
enum action {Up = 72, Down = 80, Left = 75, Right = 77, Space = 32, Enter = 13};

class Menu
{
public:
	void GotoXY(int nX, int nY);
	int Main();
};