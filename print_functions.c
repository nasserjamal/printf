#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

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

/**
 * no_char - prints and counts char
 *
 * @list: args list
 * Return: No of args
 */
int no_int(va_list list)
{
	char a = va_arg(list, int) + '0';

	write(1, &a, 1);
	return (1);
}
