#include "main.h"

/**
 *
 */

int _printf(const char *format, ...)
{
	va_list arg;
	char buffer[BUFSIZE];
	int i, no, printed;
	unsigned int str_len;

	if (format == NULL)
		return (-1);

	str_len = 0;
	printed = 0;
	no = 0;
	va_start(arg, format)

	for (i = 0; format[i] != '\0'; i++)
	{
		if (str_len > BUFSIZE)
			break;

		if (format[i] != '%')
		{
			buffer[str_len] = format[i];
			str_len++;
			if (str_len == BUFSIZE)
				_print(buffer, &strlen);
			printed++
		}
		else
		{
			_print(buffer, &strlen)
			no = handle_specifiers(format, buffer, arg, &i);
			if (no == -1)
				return (-1);
			printed + 1 = no
		}
	}
	_print(buffer, &str_len);
	va_end (arg);
	return (printed);
}

/**
 *

int _print(char *buffer, size_t str_len)
{
	int num_char;

	num_char
	if (str_len > 0)
		write (2, &buffer, str_len);

	return (num_char)
}
*/
