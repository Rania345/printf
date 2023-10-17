#include "main.h"

/**
 * print_int - prints an integer
 *
 * @arg: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 *
 * if a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_int(va_list arg, flags_t *f)
{
	int counter = va_arg(arg, int);
	int result = count_digit(counter);

	if (f->plus == 0 && f->space == 1 && counter >= 0)
		result += _putchar(' ');
	if (f->plus == 1 && counter >= 0)
		result += _putchar('+');
	if (counter <= 0)
		counter++;
	print_number(counter);
	return (result);
}

/**
 * print_decimal - prints an integer
 *
 * @arg: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 *
 * if a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_decimal(va_list arg, flags_t *f)
{
	int counter = va_arg(arg, int);
	int result = count_digit(counter);

	if (f->plus == 0 && f->space == 1 && counter >= 0)
		result += _putchar(' ');
	if (f->plus == 1 && counter >= 0)
		result += _putchar('+');
	if (counter <= 0)
		counter++;
	print_number(counter);
	return (result);
}

/**
 * print_unsigned - prints an unsigned integer
 * @arg: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list arg, flags_t *f)
{
	unsigned int u = va_arg(arg, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;

	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 *
 * @input: integer to be printed
 *
 * Return: Void
 */
void print_number(int input)
{
	unsigned int input1;

	if (input < 0)
	{
		_putchar('-');
		input1 = -input;
	}
	else
		input1 = input;

	if (input1 / 10)
		print_number(input1 / 10);
	_putchar((input1 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 *
 * @input: integer to evaluate
 *
 * Return: INT number of digits
 */
int count_digit(int input)
{
	unsigned int x = 0;
	unsigned int y;

	if (input < 0)
		y = input * -1;
	else
		y = input;
	while (y != 0)
	{
		y /= 10;
		x++;
	}
	return (x);
}
