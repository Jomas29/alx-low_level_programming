#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
#include <math.h>

/**
 * print_char - Print a char type argument.
 * @arg: The argument to print (va_list).
 */
void print_char(va_list arg)
{
char ch = va_arg(arg, int);
printf("%c", ch);
}

/**
 * print_int - Print an int type argument.
 * @arg: The argument to print (va_list).
 */
void print_int(va_list arg)
{
int num = va_arg(arg, int);
printf("%d", num);
}

/**
 * print_float - Print a float type argument.
 * @arg: The argument to print (va_list).
 */
void print_float(va_list arg)
{
double num = va_arg(arg, double);
printf("%f", num);
}

/**
 * print_string - Print a string type argument.
 * @arg: The argument to print (va_list).
 */
void print_string(va_list arg)
{
char *str = va_arg(arg, char *);

if (str == NULL)
str = "(nil)";

printf("%s", str);
}

/**
 * print_all - Prints anything according to the format specifier.
 * @format: The format specifier for the arguments passed.
 * @...: The variable number of arguments.
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0, j = 0;
char *sep = "";

va_start(args, format);

while (format && format[i])
{
j = 0;
while (j < 4)
{
if (format[i] == "cifs"[j])
{
printf("%s", sep);
switch (format[i])
{
case 'c':
print_char(args);
break;
case 'i':
print_int(args);
break;
case 'f':
print_float(args);
break;
case 's':
print_string(args);
break;
default:
break;
}
sep = ", ";
break;
}
j++;
}
i++;
}
va_end(args);
printf("\n");
}
