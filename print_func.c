#include "main.h"

/**
 *
 */

int print_char(va_list arg, char buffer[], int flags, int width, int precision, int size)
{
	int printed;
	
	char c = va_arg(arg, int);
	printed = write_char(c, buffer,flags, width, precision,size);
	return (printed);
}

/**
 *
 */

int write_char(char c, char buffer[],int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & 4)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFSIZE - i - 2] = padd;

		if (flags & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFSIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFSIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 *
 */

int print_percent(va_list arg, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(arg);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return(write(1, %%, 1));
}

/**
 *
 */

int print_str(va_list arg, char buffer[], int flags, int width, int precision, int size)
{
	int length, i;

	char *str = va_arg(arg, char*);
	UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & 1)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
