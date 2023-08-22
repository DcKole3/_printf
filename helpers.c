#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * buffer_const_char - puts constant format chars into buffer
 * @format: format string from printf
 * @buffer: buffer t output
 * @len: length of buffer contents
 * Return: number of chars put into buffer
 */
int buffer_const_char(char **format, char *buffer, unsigned int *len)
{
int printtotal = 0;
while (**format != 0 && **format != '%')
{
buffer[(*len)++] = **format;
(*format)++;
if (*len == 1024)
{
write(1, buffer, 1024);
*len = 0;
printtotal += 1024;
}
}
return (printtotal);
}
/**
 * str_len: gets length of string
 * @str: string to measure
 * Return: string length
 */
int str_len(char *str)
{
int i;
int len;
for (i = 0; str[i] != '\0'; i++)
{
len++;
}
return (len);
}
/**
 * _puts - prints a string followed by a newline
 * @s: string to print;
 * Return: number of characters printed
 */
int _puts(char *s)
{
long int len;
while (*s)
{
write(1, s, 1);
len++;
s++;
}
return (len);
}
