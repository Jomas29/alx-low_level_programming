#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints possible combinations of 3 digits
*
* Return: Always 0 (Success)
*/

int main(void)

{

int b, c, d;

for (b = 0; b <= 7; b++)
{
for (c = 1 + b; c <= 8; c++)
{
for (d = 1 + c; d <= 9; d++)
{
putchar('0' + b);
putchar('0' + c);
putchar('0' + d);

if (b != 7 && c != 8 && d != 9)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');

return (0);
}
