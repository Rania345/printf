#include "main.h"


/**
  * formatter - recognize format on passed buffer and
  * return pointer to its function
  *
  * @buffer: pointer to string
  * @index: pointer to index that start from it
  *
  * Return: (NULL) if format not recognized, otherwise pointer to function
  */
int (*formatter(const char *buffer, int *index))()
{
	/* format dictionary maps formats with it's functions */
	SpecifierHandler handlerSymbols[] = {
		{"c", printf_char},
		{"s", printf_string},
		{"d", printf_decimal},
		{"i", printf_decimal}
	};

	int symbolsLength = 4;		/* lenght of format_dic */
	int temp_index = *index;
	int j;

	/* iterate over format_dic to check if any format matched */
	while (symbolsLength--)
	{
		temp_index = *index;
		j = 0;

		while (buffer[temp_index] && handlerSymbols[symbolsLength].specifier[j]
				&& buffer[temp_index] == handlerSymbols[symbolsLength].specifier[j])
			++temp_index, ++j;

		/* current flag in format_dic matched */
		if (!handlerSymbols[symbolsLength].specifier[j])
			break;
	}
	/* no flag in format_dic matched */
	if (symbolsLength < 0)
		return (NULL);

	/* move idx to point on char after format */
	*index = temp_index;

	return (handlerSymbols[symbolsLength].functionPointer);
}


/**
  * formattedPrint - take buffer and iterate over it to handle mulitple %
  *
  * @buffer: buffer of string
  * @index: pointer to index
  * @written: pointer to writen
  *
  * Return: (1) use formated printf, (0) otherwise
  */
int formattedPrint(const char *buffer, int *index, int *written)
{
	int flag = 1;

	while (buffer[*index + 1] && buffer[*index + 1] == '%')
	{
		flag = !flag;

		if (!flag)
		{
			_putchar(buffer[*index]);
			(*written)++;
		}
		(*index)++;
	}
	(*index)++;

	return (flag);
}

/**
  * _printf - print buffer stream to output stream
  *
  * @format: buffer of chars
  * @...: formated arguments
  * Return: number of chars that printf sucessfully printed them
  */
int _printf(const char *format, ...)
{
	int index = 0,
		written = 0;

	int (*format_printf)();
	va_list argPointer;

	if (!format)		/* case of nullable buffer */
		return (-1);

	va_start(argPointer, format);

	while (format[index])
	{
		if (format[index] == '%')		/* case with formatting */
		{
			/* case if i have even number of % so i still have % not printed */
			if (!formattedPrint(format, &index, &written))
				continue;

			format_printf = formatter(format, &index);

			if (!format_printf)
			{
				_putchar('%');
				written++;
				continue;
			}

			written += format_printf(argPointer);
		}
		else		/* case of chars in buffer */
		{
			_putchar(format[index++]);
			++written;
		}
	}
	va_end(argPointer);

	return (written);
}
