#include "main.h"

/**
 *
 */

int _printf(const char *format, ...)
{
	va_list arg;
	char buffer[BUFSIZE];
	int i;
	unsigned int str_len;

	if (format == NULL)
		return (-1);
	str_len = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[str_len] = format[i];
			str_len++;
		}
	}
	write (2, &buffer, str_len);
	va_end (arg);
	return (i);
}
