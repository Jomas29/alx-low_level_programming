#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints all hexadecimal numbers in lowercase
*
* Return: Always 0 (Success)
*/

int main(void)
{
int c = 0;
for (c = 0; c < 16; c++)
{

if (c < 10)

{
putchar('0' + c);
}
else
{
putchar('a' + c - 10);
}
putchar(' ');
}
putchar('\n');

return (0);
}
