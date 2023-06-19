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

int c;

for (c = 0; c < 10; c++)
{
putchar('0' + c);
}

if (c != 9)
{
putchar(',');

putchar(' ');
}

putchar('\n');

return (0);
}
