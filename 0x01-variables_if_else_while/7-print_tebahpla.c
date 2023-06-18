#include <stdio.h>

/**
* main - Start of the program
*
* description: This program prints the alphabet in reverse
*
* return: Always 0 (Success)
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
