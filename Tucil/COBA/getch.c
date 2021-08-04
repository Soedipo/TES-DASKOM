#include <stdio.h>
//to use 'getch() function 
#include <conio.h>

int main()
{
	char a;
	// message before pressing key
	printf("Now the program is waiting for user to press a key from keyboard.\n");

	// using getch() function for reading the single byte character
	a = getch();
	if(a == 'w' || a == 'W')
	printf("CONGRATS");
	else printf("%c", a);
	return 0;
}

