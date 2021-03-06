// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include <Windows.h>
using namespace std;


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77 


class Screen {

public:
	int w;
	int h;
	Screen()
	{
		update();
	}

	int update()
	{
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		get_width(&w);
		get_height(&h);
		return 1;
	}

private:
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	int get_width(int * width)
	{
		if (width == nullptr)
			return 0;

		*width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

		return 1;
	}

	int get_height(int * height)
	{
		if (height == nullptr)
			return 0;

		*height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		return 1;
	}



};

int basic_game_loop(Screen &screen)
{

	int c = 0;
	while (1)
	{
		c = _getch();
		system("CLS");

		screen.update();
		cout << screen.w << "w x " << screen.h << "h" << endl;

		switch (c)
		{
		case KEY_UP:
			cout << endl << "Up" << flush;//key up
			break;
		case KEY_DOWN:
			cout << endl << "Down" << flush;   // key down
			break;
		case KEY_LEFT:
			cout << endl << "Left" << flush;  // key left
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << flush;  // key right
			break;
		default:
			cout << endl << "who dis?" << flush;  // not arrow
			break;
		}
	}
	return 1;
}


int main()
{

	cout << "Press any key! :-)";

	Screen screen;

	return basic_game_loop(screen);
}

