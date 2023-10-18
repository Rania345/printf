#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


/**
 * struct handler - match the conversion specifiers for printf
 *
 * @specifier: type char pointer of the specifier i.e (l, h) for
 * (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */
typedef struct handler
{
	char *specifier;
	int (*functionPointer)();
} SpecifierHandler;


int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);

void printf_dec(int number);
int printf_int(va_list arg);
int printf_decimal(va_list arg);

int _printf(const char *format, ...);

#endif
