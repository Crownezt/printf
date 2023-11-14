#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define FIND_UNUSED(x)(void)(x)
#define BUFFER_SIZE 1024
#define TAG_MINUS 1
#define TAG_PLUS 2
#define TAG_ZERO 4
#define TAG_HASH 8
#define TAG_SPACE 16
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 *struct fmt - Struct
 *
 *@fmt: The format.
 *@fn: The function associated.
 */
struct fmt
{
	char fmt;
	int(*fn)(va_list, char[], int, int, int, int);
};

/**
 *typedef struct fmt fmt_t - Struct op
 *
 *@fmt: The format.
 *@fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
	va_list list, char cache[], int tags, int width, int precision, int size);

int print_character(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_string(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_modulo(va_list args, char cache[],
	int tags, int width, int precision, int size);

int print_integer(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_bin(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_unsigned_int(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_octal(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_hexadecimal(va_list args, char cache[],
	int tags, int width, int precision, int size);
int print_hexadecimal_uppercase(va_list args, char cache[],
	int tags, int width, int precision, int size);

int hexadecimal_print(va_list args, char map_to[],
	char cache[], int tags, char flag_ch, int width, int precision, int size);

int print_unprintable(va_list args, char cache[],
	int tags, int width, int precision, int size);

int print_pointers(va_list args, char cache[],
	int tags, int width, int precision, int size);

int find_tags(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int find_precision(const char *format, int *i, va_list list);
int find_size(const char *format, int *i);

int print_rev(va_list args, char cache[],
	int tags, int width, int precision, int size);

int rot13_translation(va_list args, char cache[],
	int tags, int width, int precision, int size);

int handle_write_character(char c, char cache[],
	int tags, int width, int precision, int size);
int write_nomba(int is_positive, int ind, char cache[],
	int tags, int width, int precision, int size);
int write_numb(int ind, char bff[], int tags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointers(char cache[], int ind, int length,
	int width, int tags, char padd, char extra_c, int padd_start);

int write_unsigned_int(int is_negative, int ind,
	char cache[],
	int tags, int width, int precision, int size);

int check_printable(char);
int append_hexadecimal_code(char, char[], int);
int is_digit(char);

long int convert_number_size(long int num, int size);
long int convert_unsigned_size(unsigned long int num, int size);


#endif /*MAIN_H */
