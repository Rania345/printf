#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list argumentPointer;

	va_start(argumentPointer, format);

	PrintfSpecifier specifiers[] = {
		{"%s", printf_string}, {"%c", printf_char}, {"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	int i = 0, j, len = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

    while (*format)
	{
        if (*format == '%')
		{
            format++; // Move past '%'
            
			for (i = 0 ; i < (sizeof(specifiers) / sizeof(specifiers[0])) ; i++)
			{
                if (*format == specifiers[i].specifier) {
                    specifiers[i].handler(&argumentPointer);
                    break;
                }
            }
        }
		else
		{
            putchar(*format);
        }

        format++;
    }

    va_end(argumentPointer);
    return 0; // Return value can be changed to indicate success/failure

}
