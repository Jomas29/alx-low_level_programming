#include "main.h"

/**
* is_prime_number - Checks if a number is prime.
* @n: The number to check.
* @i: guesswd divisor
*
* Return: 1 if n is prime, 0 otherwise.
*/

int is_prime_number(int n)
{
int i;

if (n <= 1)
return (0);

for (i = 2; i * i <= n; i++)
if (n % i == 0)
return (0);

return (1);
}
