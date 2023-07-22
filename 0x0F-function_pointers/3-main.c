#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point of the calculator program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
int num1, num2, result;
int (*op_func)(int, int);

/* Check if the number of command-line arguments is correct */
if (argc != 4)
{
printf("Error\n");
return (98);
}

/* Convert the input numbers to integers using atoi function */
num1 = atoi(argv[1]);
num2 = atoi(argv[3]);

/* Get the corresponding operator function using get_op_func */
op_func = get_op_func(argv[2]);

/* Check if the operator is valid or if it's more than one character */
if (op_func == NULL || argv[2][1] != '\0')
{
printf("Error\n");
return (99);
}

/* Check if there is an attempt to divide by zero */
if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
{
printf("Error\n");
return (100);
}

/* Perform the operation using the selected operator function */
result = op_func(num1, num2);

/* Print the result */
printf("%d\n", result);

return (0);
}
