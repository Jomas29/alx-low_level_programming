#include "main.h"

/**
* print_numbers - Prints the numbers from 0 to 9 followed by a new line.
*/
void print_numbers(void)
{
int i;
char num;

for (i = 0; i <= 9; i++)
{
num = i + '0';
_putchar(num);
}

_putchar('\n');
}
