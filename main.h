#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


/**
 * struct flag - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 *
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 *
 */
typedef struct flag
{
	int plus;
	int space;
	int hash;
} flags_t;


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
	char specifier;
	int (*f)(va_list argPointer, flags_t *f);
} SpecifierHandler;


int _putchar(char c);
int print_char(va_list arg, flags_t *f);
int print_string(va_list arg, flags_t *f);

int print_int(va_list arg, flags_t *f);
int print_decimal(va_list arg, flags_t *f);
void print_number(int input);
int count_digit(int input);

int print_binary(va_list arg, flags_t *f);
int print_hex(va_list arg, flags_t *f);
int print_hexa(va_list arg, flags_t *f);
int print_octa(va_list arg, flags_t *f);

int print_rev(va_list arg, flags_t *f);
int print_exclusiveS(va_list arg, flags_t *f);
int print_percent(va_list arg, flags_t *f);
int print_rot13(va_list arg, flags_t *f);

int print_pointer(va_list arg, flags_t *f);
int print_unsigned(va_list arg, flags_t *f);

int get_flag(char symbol, flags_t *f);
char *convert(unsigned long int number, int base, int lowercase);
int (*get_specifier(char symbol))(va_list, flags_t *);
int _printf(const char *format, ...);

#endif
