#pragma once
#include<iostream>
#include<conio.h>
#include<dos.h>
#include<Windows.h>
#include<time.h>
#define MAX_SIZE 100;
#define framex 100;
#define framey 25;
using namespace std;

//bool state;

class cursor
{
public:
	void go(int x, int y);
};

class point :public cursor
{
private:
	int x, y;
public:
	point();
	point(int x, int y);
	int getx();
	int gety();
	void moveup();
	void movedown();
	void moveleft();
	void moveright();
	void draw();
	void Debug();
	void erase();
	void copy_position(point* m)
	{
		m->x = x;
		m->y = y;
	}
	void SetPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int is_same(point* p)
	{
		if (p->x == x && p->y == y)
		{
			return 1;
		}
		return 0;
	}

};

class snake
{
private:
	point* dot[100];
	int size;
	int high_score;
	int current_score;
	char direction;
	point target;
	bool state;
	bool state2;
	int started;
public:
	snake();
	void getscore(int score);
	void add_dot(int x, int y);
	void Turnup();
	void Turndown();
	void Turnleft();
	void Turnright();
	int send_high_score();
	void Move();
	void selfcollison();
	void game_play();




};

