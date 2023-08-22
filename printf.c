#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * int_str - converts integer to string
 * @arg: variadic arguments
 * Return: string of integer
 */
char *int_str(va_list arg)
{
int digits;
int j, i;
int neg_int, absMod;
int digitTest;
char *conv;
digits = va_arg(arg, int);
digitTest = digits;
j = 0;
neg_int = 0;
if (digits < 0)
{
neg_int = 1;
j++;
}
while (digitTest != 0)
{
digitTest /= 10;
j++;
}
conv = malloc(sizeof(char) * j + 1);
if (neg_int)
conv[0] = '-';
digitTest = digits;
for (i = j - 1; i >= 0 + neg_int; i--)
{
absMod = digitTest % 10;
if (absMod < 0)
{
conv[i] = -absMod + '0';
}
else
{
conv[i] = absMod + '0';
}
digitTest /= 10;
}
if (conv == NULL)
return (NULL);
conv[j] = '\0';
return (conv);
}
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
if (f_spec == 'n')
{
tmpstr[0] = 0;
return (tmpstr);
}
else if (f_spec == '%')
{
tmpstr[0] = '%';
return (tmpstr);
}
else if (f_spec == 'c')
{
tmpstr[0] = (char) va_arg(arg, int);
return (tmpstr);
}
else if (f_spec == 's')
{
tmp = va_arg(arg, char*);
return (tmp);
}
else if (f_spec == 'd' || 'i')
{
/*if (f_spec.length == 1)
return (lg_int_str(arg));
if (spec.length == -1)
return (sh_int_str(arg));
if (f_spec.length < 0)
return (sh_int_str(arg));*/
return (int_str(arg));
}
else
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
int i, lenr = 0;
unsigned int len = 0, flag = 0;
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
for (i = 0; *format != '\0'; i++)
{
if (*format == '%')
{
format++;
specifier = *format++;
tmp = stringize_arg(arg, specifier);
if (tmp == NULL)
break;
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
if (flag)
free(tmp);
}
else
printall += buffer_const_char(&format, buffer, &len);
}
va_end(arg);
lenr = write(1, buffer, len);
if (lenr == -1)
return (-1);
printall += lenr;
if (tmp == NULL)
return (-1);
return (printall);
}
