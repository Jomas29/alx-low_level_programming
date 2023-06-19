#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program print digit number with ', '
*
* Return: Always 0 (Success)
*/

int main(void)

{

char c;

for (c = 0; c < 10; c++)
{
putchar(c);
}

putchar(',');

putchar(' ');

putchar('\n');

return (0);
}
