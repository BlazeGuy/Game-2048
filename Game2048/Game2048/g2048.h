#pragma once
#include<iomanip>
#include<vector>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;
class G2048
{
private:
	vector<vector<int>> field;
	const int FIELD_EMPTY = 0;
	const int RAND1 = 2;
	const int RAND2 = 4;
	const int SIZE = 4;
public:
	G2048();
	void setConsoleColor(int textColor, int bgColor);
	void display();
	void moverandomall();
	void move();
	void moveLeft();
	void moveLeft1();
	void moveRight();
	void moveRight1();
	void moveUp();
	void moveUp1();
	void moveDown();
	void moveDown1();
	void play();
	bool lose();
};

