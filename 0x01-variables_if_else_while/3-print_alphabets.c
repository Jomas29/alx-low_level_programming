#include <stdio.h>

/**
* main - Start of the programme
*
* Description: This program prints the alphabeth in lowercase
  followed by uppercase using putchar
*
* Return: Always 0 (Success)
*/

int main(void)
{
char letter = 'a';

while (letter <= 'z')
{
putchar(letter);
letter++;
}

char letters = 'A';

while (letters <= 'Z')

{
putchar (letters);
letters++;
}

putchar('\n');

return (0);
}
