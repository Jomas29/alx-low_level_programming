#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints combination of two two-digits
*
* Return: Always 0 (Success)
*/

int main(void)
{
int b, c;
for (b = 0; b <= 99; b++)
{
for (c = b; c <= 99; c++)
{
if (b != c)
{
putchar('0' + b / 10);
putchar('0' + b % 10);
putchar(' ');
putchar('0' + c / 10);
putchar('0' + c % 10);
if (b != 98 && c != 99)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
}
return (0);
}
