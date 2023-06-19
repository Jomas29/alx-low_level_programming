#include <stdio.h>

/**
*main - Start of the program
*
* Description: This program prints distinct combination of 2 digits
*
* Return: Always 0 (Success)
*/

int main(void)
{
for (int c = 0; c <= 8; c++)
{
for (int d = c + 1; d <= 9; d++)
{
putchar('0' + c);
putchar('0' + d);
if (c != 8 || d != 9)
{
putchar(',');
putchar(' ');
}
}
}
return (0);
}
