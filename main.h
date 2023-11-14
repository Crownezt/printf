#ifndef PRINTF_HEADER
#define PRINTF_HEADER
#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);
#endif
