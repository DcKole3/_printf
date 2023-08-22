#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct spec - specifiers for func
 * @specifier: handles for data type e.g i - int
 */
typedef struct spec
{
  char specifier;
} spec;
/**
 * helper.c 
 */
int str_len(char *str);
int _puts(char *s);
/**
 *Prototypes of int_to_str.c
 */
char *int_str(va_list arg);
char *sh_int_str(va_list arg);
char *lg_int_str(va_list arg);
/**
 * printf.c prototype
 */
char *stringize_arg(va_list list, char f_spec);
int _printf(char *format, ...);
#endif
