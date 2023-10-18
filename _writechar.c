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
	return (write(1, &c, 1));
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
 * printf_char - prints a character
 *
 * @arg: va_list arguments from _printf
 *
 * Return: number of char printed
 */
int printf_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * printf_string - loops through a string and prints every character
 *
 * @arg: va_list arguments from _printf
 *
 * Return: number of char printed
 */
int printf_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
