#include "main.h"

#include <stdio.h>

/**
* print_alphabet - Prints the alphabet in lowercase, followed by a new line.
*
* Return: None.
*/
void print_alphabet(void)
{
char letter = 'a';

while (letter <= 'z')
{
putchar(letter);
letter++;
}

putchar('\n');
}
