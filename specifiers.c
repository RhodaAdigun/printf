#include "main.h"

/**
 *
 */

handle_specifiers(const char *format, char buffer[], va_list arg, int i)
{
	specifier_t specifier[];
	int index;

	specifier[] ={
		{'c', print_char}, {'s', print_str},{'%', print_percent},
		{'d', print_int}, {'i', print_int},{' ', NULL}, {'\0', NULL};
	}
	if (format[i + 1] == '\0')
		return(-1);

	for (index = 0; specifer[index].specifier != '\0'; index++)
	{
		if (format[i + 1] == specifer[index].specifier)
		{
			len = specifier.(*func)(va_list arg, char buffer[], int i);
			return (len);
		}
	}

