#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 *
 */
typedef struct specifier
{
	char *specifier;
	int (*func)(va_list, char [], int);
}specifier_t;

int _printf(const char *format, ...);
handle_specifiers(const char *format, char buffer[], va_list arg, int i);
//int print(char *buffer, size_t str_len);

#endif
