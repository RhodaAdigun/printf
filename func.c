#include "main.h"

/**
 *
 */

void _print(char buffer[], int *str_len)
{
	if(*str_len > 0)
		write(1, &buffer[0], *str_len);
	*str_len = 0;
}

/**
 *
 */

int _size(const char *format, int *i)
{
	int size, c;

	int size = 0;
	int c = *i + 1;

	if (format[c] == 'h')
		size = 1;
	else if (format[c] == l)
		size = 2;

	if (size == 0)
		*i = c - 1;
	else
		*i = c;

	return (size);
}

/**
 *
 */

int _flags(const char *format, int *i)
{
	int c,flag,ind;

	flag = 0;
	c = *i + 1;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {1, 2, 4, 8, 16, 0};

	for (; format[c] != '\0'; c++)
	{
		for (j = 0; FLAGS_CH[ind] != '\0'; ind++)
		{
			if (format[c] == FLAG_CH[ind])
			{
				flag |= FLAG_ARR[ind];
				break;
			}
		}
		if (FLAG_CH[ind] == 0)
			break;
	}
	*i = c - 1;
	return (flag);
}

/**
 *
 */

int _precision(const char *format, int *i, va_list arg)
{
	int c = *i + 1;
	int precision = -1;

	if (format[c] != '.')
		return (precision);

	precision = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			precision *= 10;
			precision += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (precision);
}


/**
 *
 */

int _width(const char *format, int *i, va_list arg)
{
	int c, width;

	c = *i + 1;
	width = 0;

	for (;format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			width *= 10;
			width += format[c] - '0';
		}
		else if(format[c] == '*')
		{
			width = va_arg(arg, int);
			c++;
			break;
		}
		else
			break;
	}
	*i = c - 1;
	return (width);
}
