#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program states if the last digit of a random number is greater than 5,equal to 0 or less than 6 but not 0
*
* Return 0 Always (Success)
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
 
	return (0);
}
