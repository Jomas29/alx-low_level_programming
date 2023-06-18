#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

/**
* main - Start of the program
*
* Description: This program states if the last digit of a random number
*              is greater than 5,equal to 0 or less than 6 but not 0
*
* Return: 0 Always (Success)
*/

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is %d and is", n, (n % 10));

if ((n % 10) > 5)
printf(" greater than 5\n");

else if ((n % 10) == 0)
printf(" 0\n");

else
printf(" less than 6 and not 0\n");

	return (0);
}
