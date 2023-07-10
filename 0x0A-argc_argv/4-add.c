#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - Entry point of the program
* @argc: The argument count
* @argv: The argument vector
*
* Return: 0 on success, 1 on error
*/

int main(int argc, char *argv[])
{
int sum = 0;
int i;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
int num = 0;
int j;

for (j = 0; argv[i][j] != '\0'; j++)
        {
if (argv[i][j] < '0' || argv[i][j] > '9')
{
printf("Error\n");
return (1);
}

num = num * 10 + (argv[i][j] - '0');
}

sum += num;
}

printf("%d\n", sum);
return (0);
}
