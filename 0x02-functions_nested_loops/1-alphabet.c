#include "main.h"

int _putchar(char c);

int main(void)
{
print_alphabet();
return 0;
}

/**
* print_alphabet - Prints the alphabet in lowercase followed by a new line.
*/
void print_alphabet(void)
{
for (char letter = 'a'; letter <= 'z'; letter++)
{
_putchar(letter);
}

_putchar('\n');
}

int _putchar(char c)
{
return putchar(c);
}
