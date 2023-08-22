#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
