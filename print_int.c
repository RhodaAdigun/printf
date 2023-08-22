#include "main.h"

/**
 *
 */

int print_int(va_list arg, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	int is_negative = 0;
	long int n = va_arg(arg, long int);
	unsigned long int num;

	n = convert_size(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 *
 */

long int convert_size(long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((short)num);

	return((int)num);
}

/**
 *
 */

int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFSIZE - i - 1;
	char padd = ' ', ch = 0;

	UNUSED(size);

	if ((flags & 4) && !(flags & 1))
		padd = '0';
	if (is_negative)
		ch = '-';
	else if (flags & 2)
		ch = '+';
	else if (flags & 16)
		ch = ' ';
	return(write_num(i, buffer, flags, width, precision, length, padd, ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */

int write_num(int ind, char buffer[],int flags, int width, int prec,int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & 1 && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & 1) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & 1) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
