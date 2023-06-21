#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints _putchar
*
* Return: Always 0 (Success)
*/

int main(void)
{
char alp[8] = "_putchar";
int i;

for (i = 0; i <= 7; i++)
{
putchar(alp[i]);
}

putchar('\n');

return (0);
}
