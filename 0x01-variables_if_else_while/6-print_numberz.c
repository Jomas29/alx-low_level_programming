#include <stdio.h>

/**
* main - Statr of the program
*
* Description: This program prints all single digit numbers of base 10
*
* Return: Always 0 (Success)
*/

int main(void)
{
int digit;
for (digit = 0; digit <= 9; digit++)
{
putchar('0' + digit);
}

putchar('\n');

return (0);
}
