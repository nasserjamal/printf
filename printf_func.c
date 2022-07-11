#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int printed_chars = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	while (*format)
    {
        if(*format == '\0')
        break;
        if(*format == '%')
        {
            printed_chars += compute_args(*(format++), arg_list);
        }else
        {
            printed_chars++;
        }
        format++;
    }
        
	va_end(arg_list);
	return (printed_chars);
}

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

int no_char(va_list list){
    (void)list;
return(1);
}

int no_string(va_list list){
return(strlen(va_arg(list, char *)));
}

int no_percent(va_list list){
    (void)list;
return(1);
}
