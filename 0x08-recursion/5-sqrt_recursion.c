#include "main.h"

/**
* sqrt_helper - Helper function to calculate square root recursively.
* @n: The number to calculate the square root of.
* @guess: The current guess for the square root.
*
* Return: The square root of n if found, otherwise -1.
*/
int sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess);
else if (guess * guess > n)
return (-1);
else
return (sqrt_helper(n, guess + 1));
}

/**
* _sqrt_recursion - Calculates the natural square root of a number.
* @n: The number to calculate the square root of.
*
* Return: The square root of n if found, otherwise -1.
*/
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (sqrt_helper(n, 0));
}
