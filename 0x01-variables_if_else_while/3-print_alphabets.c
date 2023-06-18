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
char letter, letters;

/* Print lowercase alphabets */
 for (letter = 'a'; letter <= 'z'; letter++)

{
putchar(letter);
}

/* Print uppercase alphabets */
 for (letters = 'A'; letters <= 'Z'; letters++)

{
putchar (letters);
}

putchar('\n');

return (0);
}
