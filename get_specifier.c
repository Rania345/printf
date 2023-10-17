#include "main.h"

/**
 * get_print - selects the appropriate function based on
 * the conversion specifier passed to _printf
 *
 * @symbol: Conversion specifier parameter
 *
 * Description: Function loops through the array of structs
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 *
 * Return: a pointer to the matching printing function
 */

int (*get_specifier(char symbol))(va_list, flags_t*)
{
	SpecifierHandler specifierStructs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_int},
		{'u', print_unsigned},
		{'b', print_binary},
		{'o', print_octa},
		{'x', print_hex},
		{'X', print_hexa},
		{'S', print_exclusiveS},
		{'p', print_pointer},
		{'r', print_rev},
		{'R', print_rot13}
	};

	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
	{
		if (specifierStructs[i].specifier == symbol)
		{
			return (specifierStructs[i].pointerToFunctions);
		}
	}
	return (NULL);
}


/**
 * get_flag - turns on flags if _printf finds
 *
 * @symbol: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char symbol, flags_t* f)
{
	int i = 0;

	switch (symbol)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
