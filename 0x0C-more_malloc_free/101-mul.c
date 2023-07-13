#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 *
 * Return: On success, returns the character written. On error, returns -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _strlen - Calculates the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return len;
}

/**
 * _atoi - Converts a string to an integer
 * @s: The input string
 *
 * Return: The converted integer value
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return sign * result;
}

/**
 * main - Multiply two positive numbers
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int num1 = 0, num2 = 0, result = 0;
	char *num1_str = argv[1];
	char *num2_str = argv[2];

	/* Check the number of arguments */
	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (98);
	}

	/* Convert the input numbers to integers */
	while (*num1_str && *num1_str >= '0' && *num1_str <= '9')
	{
		num1 = num1 * 10 + (*num1_str - '0');
		num1_str++;
	}

	while (*num2_str && *num2_str >= '0' && *num2_str <= '9')
	{
		num2 = num2 * 10 + (*num2_str - '0');
		num2_str++;
	}

	/* Validate the input numbers */
	if (*num1_str != '\0' || *num2_str != '\0' || num1 <= 0 || num2 <= 0)
	{
		write(2, "Error\n", 6);
		return (98);
	}

	/* Perform the multiplication */
	result = num1 * num2;

	/* Print the result */
	int digit_count = 0;
	int temp = result;

	while (temp > 0)
	{
		temp /= 10;
		digit_count++;
	}

	char digits[digit_count];

	for (int i = digit_count - 1; i >= 0; i--)
	{
		digits[i] = result % 10 + '0';
		result /= 10;
	}

	for (int i = 0; i < digit_count; i++)
		_putchar(digits[i]);

	_putchar('\n');

	return (0);
}
