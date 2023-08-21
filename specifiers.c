#include "main.h"

/**
 * handle_specifiers - handles the specifiers
 */

handle_specifiers(const char *format, char buffer[], va_list arg, int i)
{
	specifier_t specifier[];
	int flag, size, precision, width;
	int index, len, printed;

	len = 0;
	printed = -1;

	specifier[] ={
		{'c', print_char}, {'s', print_str},{'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'\0', NULL};
	}

	flag = _flags(format, &i);
	width = _width(format, &i, arg);
	precision = _precision(format, &i, arg);
	size = _size(format, &i);

	if (format[i + 1] == '\0')
		return(-1);

	for (index = 0; specifer[index].specifier != '\0'; index++)
	{
		if (format[*i] == specifer[index].specifier)
		{
			return (specifier[index].func(arg, buffer, flag, width, precision, size);
		}
	}

	if (specifier[i].specifier == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (formatmt[*i - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printed);
}

