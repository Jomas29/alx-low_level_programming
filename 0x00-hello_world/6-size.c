#include <stdio.h>

/**
* main - Start of the program
*
* Description: This program prints the size of various types
*
* Return: Always 0 (success)
*/
int main(void)
{
fprintf(stderr, "size of a char: %zu byte(s)\n", sizeof(char));
fprintf(stderr, "size of an int: %zu byte(s)\n", sizeof(int));
fprintf(stderr, "size of a float: %zu byte(s)\n", sizeof(float));
fprintf(stderr, "size of a long int: %zu byte(s)\n", sizeof(long));
fprintf(stderr, "size of a long long int: %zu byte(s)\n", sizeof(long long));

return (0);
}
