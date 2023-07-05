#include "main.h"

/**
* factorial - calculates the factorial of a number
* @n: The number whose factorial is to be calculated
*
* Return: int
*/

int factorial(int n)
{
if (n < 0)
{
return (-1);
}
if (n == 0)
{
return (1);
}

return (n * factorial(n - 1));
}
