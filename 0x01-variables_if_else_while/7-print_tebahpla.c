#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints the alphabet in reverse
*
* Return: Always 0 (Success)
*/

int main(void)

{

char letter;

for (letter = 'z'; letter >= 'a'; letter--)

{

putchar(letter);

}

putchar('\n');

return (0);

}
