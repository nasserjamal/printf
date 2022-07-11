#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct symbol
{
	char *sym;
	int (*f)(va_list);
};
typedef struct symbol symbol_t;

int _printf(const char *format, ...);
int compute_args(char sign, va_list args);
int no_char(va_list);
int no_string(va_list);
int no_percent(va_list);
int no_int(va_list);

#endif
