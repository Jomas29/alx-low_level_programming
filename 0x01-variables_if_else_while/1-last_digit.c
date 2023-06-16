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

int length = strlen(%d, n);
char lastChar = str[length -1]
int lastDigit = lastChar -'0';

 If (lastChar > 5)
{
printf("Last digit of %d is lastDigit and is greater than 5\n", n)
}

else if (lastChar == 0)
{
printf("Last digit of %d is lastDigit and is zero\n", n)
)

else
{
printf("Last digit of %d is lastDigit and is less than 6 and not 0\n", n)
}
	return (0);
}
