#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int con_print(const char *format, int *i,
va_list view, char buffer[], int flag, int wid, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_string(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flag, int wid, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flag, char flag_ch, int wid, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

<<<<<<< HEAD
/* Function to handle other specifiers */
int get_flags(const char *format, int *i);
=======
/* Funciotns to handle other specifiers */
int calc_flag(const char *format, int *i);
<<<<<<< HEAD
int print_width(const char *format, int *i, va_list view);
int calc_precision(const char *format, int *i, va_list view);
int get_size(const char *format, int *i);
||||||| 1803edd
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
=======
>>>>>>> 1803edddcc57daff38b389f7bf6ab8efd3c0bfb0
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *n);
>>>>>>> 7578fa0a8eedd693b84a3441a23186cf018ddbe5

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flag, int wid, int precision, int size);

/** Handler **/
int _handler(char c, char buffer[],
	int flag, int wid, int precision, int size);
int _numbers(int is_negative, int d, char buffer[],
	int flag, int wid, int precision, int size);
int buf_num(int d, char buffer[], int flag, int wid, int precision,
	int length, char hnd, char extra_c);
int un_num(int is_negative, int d, char buffer[], int flag, int wid, int precision, int size);
int new_pointer(char buffer[], int d, int length,
        int wid, int flag, char hnd, char extra_c, int buf_pad)

/** Converts **/
int is_print1(char c);
int is_append(char ascii_code, char buffer[], int n);
int is_digit(char c);
long int convert_size(long int m, int size);
long int convert_size1(unsigned long int m, int size);

#endif 

