#include "main.h"

/**
* _sqrt_recursion - Computes the natural square root of a number.
* @n: The number to compute the square root of.
*
* Return: The natural square root of 'n', or -1 if 'n' does not have a
*         natural square root.
*/
int _sqrt_recursion_helper(int n, int guess)
{
if (guess * guess == n)
return guess;
if (guess * guess > n)
return (-1);
return (_sqrt_recursion_helper(n, guess + 1));
}

int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_sqrt_recursion_helper(n, 0));
}
