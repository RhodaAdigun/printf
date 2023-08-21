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
	char specifier;
	int (*func)(va_list, char [], int, int, int,int);
}specifier_t;

int _printf(const char *format, ...);
handle_specifiers(const char *format, char buffer[], va_list arg, int *i);
void _print(char buffer[], int *str_len);
int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list arg);
int _precision(const char *format, int *i, va_list arg);
int _size(const char *format, int *i);

#endif
