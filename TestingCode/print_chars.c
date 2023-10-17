#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * 
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 *
 * @arg: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 *
 * if a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_char(va_list arg, flags_t* f)
{
	(void)f;
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_string - loops through a string and prints every character
 *
 * @arg: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 *
 * if a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_string(va_list arg, flags_t* f)
{
	(void)f;

	char* str = va_arg(arg, char*);

	if (!str)
		str = "(null)";

	return (_puts(str));
}
