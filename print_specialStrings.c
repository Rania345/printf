#include "main.h"


/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_exclusiveS(va_list arg, flags_t *f)
{
	int i, count = 0;
	char *result;
	char *str = va_arg(arg, char*);

	(void)f;

	if (!str)
		return (_puts("(null)"));

	for (i = 0 ; str[i] ; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			result = convert(str[i], 16, 0);

			if (!result[1])
				count += _putchar('0');

			count += _puts(result);
		}
		else
			count += _putchar(str[i]);
	}

	return (count);
}

/**
 * print_rev - prints a string in reverse
 *
 * @arg: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 *
 * Return: length of the printed string
 */
int print_rev(va_list arg, flags_t *f)
{
	int i = 0, j;
	char *str = va_arg(arg, char*);

	(void)f;

	if (!str)
		str = ")llun(";

	while (str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 *
 * @arg: list of arguments from _printf
 * @f: pointer to the struct flags
 *
 * Return: length of the printed string
 */
int print_rot13(va_list arg, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg, char*);

	(void)f;

	for (j = 0 ; str[j] ; j++)
	{
		if (str[j] < 'A' || (str[j] > 'Z' && str[j] < 'a') || str[j] > 'z')
			_putchar(str[j]);
		else
		{
			for (i = 0 ; i <= 52 ; i++)
			{
				if (str[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_percent - prints a percent
 *
 * @arg: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: number of char printed
 */
int print_percent(va_list arg, flags_t *f)
{
	(void)arg;
	(void)f;

	return (_putchar('%'));
}
