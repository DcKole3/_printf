#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * stringize_arg - Sends int va_arg to needed func
 * or returns a string or char
 * @arg: va_list to pop from
 * @f_spec: struct of specifier info
 * Return: string to print
 */
char *stringize_arg(va_list arg, char f_spec)
{
static char tmpstr[2] = {0, 0};
char *tmp;
switch (f_spec)
{
case 'n':
tmpstr[0] = 0;
return (tmpstr);
case '%':
tmpstr[0] = '%';
return (tmpstr);
case 'c':
tmpstr[0] = (char) va_arg(arg, int);
return (tmpstr);
case 's':
tmp = va_arg(arg, char*);
return (tmp);
case 'd':
case 'i':
/*if (f_spec.length == 1)
return (lg_int_str(arg));
if (spec.length == -1)
return (sh_int_str(arg));
if (f_spec.length < 0)
return (sh_int_str(arg));*/
return (int_str(arg));
}
return (NULL);
}
/**
 * _printf - prints a formatted string with given arguments
 * @format: string/specifier to use
 * Return: characters printed, or -1 on error
 */
int _printf(char *format, ...)
{
unsigned int printall;
char *tmp, *ptr, buffer[1024];
va_list arg;
char specifier;
int lenr = 0;
unsigned int len = 0;
if (format == NULL)
return (-1);
tmp = buffer;
va_start(arg, format);
if (format[0] == '%' && format[1] == 's' && format[2] == '\n'
    && format[3] == 0)
{
printall = puts(va_arg(arg, char *));
va_end(arg);
return (printall);
}
while (*format)
{
if (*format == '%')
{
format++;
specifier = *format;
tmp = stringize_arg(arg, specifier);
ptr = tmp;
while (*ptr)
{
buffer[len++] = *ptr++;
if (len == 1024)
{
lenr = write(1, buffer, 1024);
if (lenr == -1)
return (-1);
printall += lenr;
len = 0;
}
}
}
}
va_end(arg);
return (printall);
}
