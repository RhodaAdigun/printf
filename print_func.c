#include "main.h"

/**
 *
 */

int print_char(va_list arg, char buffer[], int i)
{
	char c = va_arg(arg, int);
	buffer[i++] = c;
	return (write(1,&buffer[0],1);
}
