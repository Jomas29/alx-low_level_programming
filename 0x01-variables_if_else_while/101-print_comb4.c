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

for (b = 0; b <= 9; b++)
{
for (c = 1 + b; c <= 8; c++)
{
for (d = 1 + c; d <= 7; d++)
{
putchar('0' + b);
putchar('0' + c);
putchar('0' + d);
}
putchar(',');
putchar(' ');
}
}
putchar('\n');

return (0);
}
