#include <stdio.h>

/**
* main - Start of the programme
*
* Description: This program prints the alphabeth except q and e in lowercase
*
* Return: Always 0 (Success)
*/

int main(void)
{
char letter;

/* Print lowercase alphabets */
for (letter = 'a'; letter <= 'z'; letter++)

{
if (letter != 'q' && letter != 'e')
{
putchar(letter);
}
}

putchar('\n');

return (0);
}
