#include <stdio.h>


int main() 
{
	char string[80];

	printf("What is your name?\n");
	fgets(string, 80, stdin);
	printf("Sup, %syou're stupid.\n", string);

	return 0;

}