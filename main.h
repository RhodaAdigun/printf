#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFSIZE 1024
#define UNUSED(x) (void)(x)

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

int print_char(va_list arg, char buffer[], int flags, int width, int precision, int size);
int write_char(char c, char buffer[],int flags, int width, int precision, int size);
int print_percent(va_list arg, char buffer[], int flags, int width, int precision, int size);
int print_str(va_list arg, char buffer[], int flags, int width, int precision, int size);

int print_int(va_list arg, char buffer[], int flags, int width, int precision, int size);
long int convert_size(long int num, int size);
int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],int flags, int width, int prec,int length, char padd, char extra_c);

#endif
