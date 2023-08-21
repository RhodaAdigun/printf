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
