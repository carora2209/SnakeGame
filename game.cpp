#include<iostream>
#include<conio.h>
#include"game.h"
#include<Windows.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cursorloc;

// This function is used make the curser to go the point as received by the coordinate 
void cursor::go(int x, int y)
{
	Cursorloc.X = x;
	Cursorloc.Y = y;
	SetConsoleCursorPosition(console, Cursorloc);
}

// constructor function to assign values to the coordinates 
point::point() : x(10), y(10) {}

//Parameter constructor to give values received in the parameter
point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}

// Getter to return x
int point::getx()
{
	return x;
}

// Getter to return x
int point::gety()
{
	return y;
}

//function to move up
void point::moveup()
{
	y--;

	try
	{
		if (y < 0) throw 1;
	}

	catch (int e)
	{
		y = 25;
	}
}

//move down function
void point::movedown()
{
	y++;

	try
	{

		if (y > 25) throw 1;
	}

	catch (int e)
	{
		y = 0;
	}

}

//move left function 
void point::moveleft()
{
	x--;


	try
	{
		if (x < 0) throw 1;
	}

	catch (int e)
	{
		x = 25;
	}
}

//move right function  
void point::moveright()
{
	x++;

	try
	{
		if (x > 100) throw 1;
	}

	catch (int e)
	{
		x = 0;
	}
}

//draw function to draw the '*'
void point::draw()
{
	go(x, y);
	cout << "*";
}

// NOT IMPORATANT USED DURING DEVELOPMENT
void point::Debug()
{
	cout << x << "," << y;
}

// dispalying " "
void point::erase()
{
	cout << " ";
}

// snake costructor just to intialise variables and define array of points
snake::snake()
{
	high_score = 0;
	state2 = false;
	current_score = 0;
	size = 1;
	state = true;
	dot[0] = new point(20, 20);
	for (int i = 1; i < 100; i++)
	{
		dot[i] = NULL;
	}
	target.SetPoint(rand() % 100, rand() % 25);
}

// setter to set the received score of the user 
void snake::getscore(int score)
{
	high_score = score;
}

// add dot to increase the snake's length , we use dynamic memeory handling here 
void snake::add_dot(int x, int y)
{
	dot[size++] = new point(x, y);
}

// turn up function this takes up input and sets the direction
void snake::Turnup()
{



	try
	{
		if (direction != 's') throw 'a';
	}

	catch (char a)
	{
		direction = 'w';
	}
}

// turn down function this takes up input and sets then direction
void snake::Turndown()
{
	try
	{
		if (direction != 'w') throw 'a';
	}

	catch (char a)
	{
		direction = 's';
	}
}

// turn left function this takes up input and sets then direction
void snake::Turnleft()
{
	try
	{
		if (direction != 'd') throw 'c';
	}

	catch (char c)
	{
		direction = 'a';
	}
}

// turn right function this takes up input and sets then direction
void snake::Turnright()
{
	if (direction != 'a')
	{
		direction = 'd';
	}
}

// this to return the user's high score
int snake::send_high_score()
{
	return high_score;
}

// Move function does all major things , show menu when the game is lost, dsipaly score while playing
// checking for self collison state ,makeing snake follow itself , calling functions for moevement
void snake::Move()
{
	system("cls");
	cout << "Your SCORE IS :" << current_score;

	if (state2 == true) {
		if (!started) {
			cout << "\n\nPress any key to start";
			_getch();
			started = 1;
			state = true;
		}
		else {




			try
			{

				if (current_score > high_score) throw 1;


			}
			catch (int e)
			{
				cout << "WOHOO!! THIS IS YOUR HIGHEST SCORE";
				high_score = current_score;
			}





			current_score = 0;
			while (1)
			{
				int choice;
				cout << "\nGame Over";
				cout << "Press 1 to exit\n";
				cout << "Press 2 of you to start again\n";
				cin >> choice;
				if (choice == 1)
				{
					state = false;
					game_play();
					break;
				}
				else if (choice == 2)
				{
					state = true;
					size = 1;
					game_play();
					break;
				}
				else
				{
					cout << "WRONG INPUT, TRY AGAIN";
				}
			}
		}
	}



	// move snake body behind it
	for (int i = size - 1; i > 0; i--) {
		dot[i - 1]->copy_position(dot[i]);
	}

	//turning snake's head 
	if (direction == 'w')
	{
		dot[0]->moveup();
	}
	else if (direction == 'a')
	{
		dot[0]->moveleft();
	}
	else if (direction == 's')
	{
		dot[0]->movedown();
	}
	else if (direction == 'd')
	{
		dot[0]->moveright();
	}

	selfcollison();

	// collison with target
	if (target.getx() == dot[0]->getx() && target.gety() == dot[0]->gety())
	{
		current_score++;
		add_dot(0, 0);
		target.SetPoint(rand() % 100, rand() % 25);
	}

	// draw snake
	for (int i = 0; i < size; i++)
	{
		dot[i]->draw();
	}
	target.draw();
	Sleep(50);
}

// self colllison checks if the function touches itself
void snake::selfcollison()
{
	for (int i = 1; i < size; i++)
	{
		if (dot[0]->is_same(dot[i]))
		{
			state2 = true;
		}
	}

}

// outer wrapper function somthing with which the user will fiddle with intially.
void snake::game_play()
{
	state2 = false;
	char input = 'l';
	do {
		/*if (_kbhit()) {
			input = _getch();
		}*/
		int x = 1;
		try
		{
			if (_kbhit()) throw 1;
		}
		catch (int x)
		{
			input = _getch();
		}
		if (input == 's' || input == 'S')
		{
			Turndown();
		}
		else if (input == 'W' || input == 'w')
		{
			Turnup();
		}
		else if (input == 'A' || input == 'a')
		{
			Turnleft();
		}
		else if (input == 'D' || input == 'd')
		{
			Turnright();
		}

		if (state == false)
			break;


		Move();

		/*score = send_high_score();*/

	} while (input != 'm');


}
