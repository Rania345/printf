
#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * format, ...)
{
	int (*pointerFunc)(va_list, flags_t*);
	const char* ptr;
	va_list arguments;

	flags_t flags = { 0, 0, 0 };

	register int count = 0;

	va_start(arguments, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (ptr = format ; *ptr ; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*ptr, &flags))
				ptr++;

			pointerFunc = get_print(*ptr);
			count += (pointerFunc)
				? pointerFunc(arguments, &flags)
				: _printf("%%%c", *ptr);
		}
		else
			count += _putchar(*ptr);
	}
	_putchar(-1);
	va_end(arguments);

	return (count);
}
