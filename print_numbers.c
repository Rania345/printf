#include "main.h"

/**
 * printf_dec - prints a decimal number
 *
 * @number: va_list of arguments from _printf
 *
 * Return: number
 */
void printf_dec(int number)
{
	if (!num)
		return;

	printf_dec(number / 10);

	_putchar((number % 10) + '0');
}


/**
  * printf_decimal - print integers
  *
  * @arg: integer
  *
  * Return: number of digits printed
  */
int printf_decimal(va_list arg)
{
	int number = va_arg(arg, int);
	int digit_count = 0;
	int temp = number;

	if (number < 0)
	{
		_putchar('-');
		number *= -1;
		digit_count++;
	}

	if (number == 0)
	{
		_putchar('0');
		digit_count++;
	}

	while (temp > 0)
	{
		temp /= 10;
		digit_count++;
	}

	printf_dec(number);

	return (digit_count);
}

/**
 * printf_int - prints an integer
 *
 * @arg: va_list of arguments from _printf
 *
 * Return: number of char printed
 */
int printf_int(va_list arg)
{
	return (printf_decimal(arg));
}
