#include <stdio.h>
//to use 'gotoxy()' and 'getch()'
#include <conio.h>
#include <windows.h>

int main()
{
	// define the type of variables
	int x=0, y=1;

	// define the value of variables


	// change cursor position on further co-ordinates.
	gotoxy(x,y);

	// message
	printf("The position of cursor is changed");

	// for killing the execution
	getch();
	return 0;
}

int gotoxy(int x,int y)
{
COORD co;
co.X=x;
co.Y=y;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), co);
return 0;
}
