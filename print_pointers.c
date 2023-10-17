#include "main.h"

/**
 * print_address - prints address of input in hexa format
 *
 * @arg: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_pointer(va_list arg, flags_t* f)
{
	char* str;
	unsigned long int ptr = va_arg(arg, unsigned long int);

	register int count = 0;

	(void)f;

	if (!ptr)
		return (_puts("(nil)"));

	str = convert(ptr, 16, 1);
	count += _puts("0x");
	count += _puts(str);

	return (count);
}
