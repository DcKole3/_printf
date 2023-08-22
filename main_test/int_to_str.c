#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
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
 * lg_int_str - converts long integer to string
 * @arg: variadic arguments
 * Return: string of integer
 */
/*char *lg_int_str(va_list arg)
{
long int digits;
int j, i;
int neg_int, absMod;
long int digitTest;
char *conv;
digits = va_arg(arg, long int);
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

 * sh_int_str - converts short integer to string
 * @arg: variadic arguments
 * Return: string of integer
 *
char *sh_int_str(va_list arg)
{
char digits;
int j, i;
int neg_int, absMod;
char digitTest;
char *conv;
digits = (char) va_arg(arg, int);
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
}*/

