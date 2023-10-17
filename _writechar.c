#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 * Description: _putchar uses a local buffer of 1024 to call write
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buffer, i);
		i = 0;
	}

	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 *
 * @str: pointer to the string to print
 *
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
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
int print_char(va_list arg, flags_t *f)
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
int print_string(va_list arg, flags_t *f)
{
	(void)f;

	char *str = va_arg(arg, char*);

	if (!str)
		str = "(null)";

	return (_puts(str));
}
