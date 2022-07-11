#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints characters passed as argument
 *
 * @format: named string args
 * @...: unnammed string args
 * Return: No of characters
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
    int tempNo = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*format)
	{
	if (*format == '\0')
		break;
	if (*format == '%')
	{
		tempNo = compute_args(*(++format), arg_list);
	if (tempNo != -1)
		printed_chars += tempNo;
	} else
	{
		printed_chars++;
		write(1, format, 1);
	}
	format++;
	}

	va_end(arg_list);
	return (printed_chars);
}


/**
 * compute_args - Sorts out the arguments
 *
 * @sign: the character conversion symbol
 * @args: argument list
 * Return: int no of characters
 */
int compute_args(char sign, va_list args)
{
int ans = 0;
int j;
symbol_t f_list[] = {
		{"c", no_char},
		{"s", no_string},
		{"%", no_percent},
		{NULL, NULL}
	};
for (j = 0; f_list[j].sym != NULL; j++)
{
	if (sign == f_list[j].sym[0])
	{
		ans = f_list[j].f(args);
		if (ans == -1)
			return (-1);
		return (ans);
	}
	}
	return (-1);
}

/**
 * no_char - prints and counts char
 *
 * @list: args list
 * Return: No of args
 */
int no_char(va_list list)
{
	char a = va_arg(list, int);

	write(1, &a, 1);
	return (1);
}

/**
 * no_string - prints and counts string
 *
 * @list: args list
 * Return: No of args
 */
int no_string(va_list list)
{
	char *a = va_arg(list, char*);

	write(1, a, strlen(a));
	return (strlen(a));
}


/**
 * no_percent - prints and counts percentage
 *
 * @list: args list
 * Return: No of chars
 */
int no_percent(va_list list)
{
	va_arg(list, int);

	write(1, "%", 1);
	return (1);
}
