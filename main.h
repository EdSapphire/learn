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
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @format_t: The function associated.
 */
typedef struct format format_t;

/*** PRINTF ***/
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_d);
int con_print(const char *format, int *i,
va_list view, char buffer[], int flag, int wid, int precision, int size);

/****************** FUNCTIONS ******************/

/** Print chars and strings **/
int write_char(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int _string1(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int cal_percent(va_list type, char buffer[],
	int flag, int wid, int precision, int size);

/** Print numbers **/
int new_int(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int _binary(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int int_num(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int int_octal(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int hex_decimal(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int hexa_upper1(va_list type, char buffer[],
	int flag, int wid, int precision, int size);
int hex_low(va_list type, char map_to[],
char buffer[], int flag, char flag_ch, int wid, int precision, int size);

/** Print non printable characters **/
int non_chars(va_list type, char buffer[],
	int flag, int wid, int precision, int size);

/** Print address **/
int var_ptr(va_list type, char buffer[],
	int flag, int wid, int precision, int size);

/** Print string in reverse **/
int _reverse(va_list type, char buffer[], int flag, int wid, int
		precision, int size);

/** Print a string in rot 13*/
int rot13_str(va_list type, char buffer[],
	int flag, int wid, int precision, int size);

/** FLAGS ***/
int calc_flag(const char *format, int *i);
int print_width(const char *format, int *i, va_list view);
int calc_precision(const char *format, int *i, va_list view);
int cal_size(const char *format, int *n);

/** HANDLERS **/
int _handler(char c, char buffer[],
	int flag, int wid, int precision, int size);
int _numbers(int is_negative, int d, char buffer[],
	int flag, int wid, int precision, int size);
int buf_num(int d, char buffer[], int flag, int wid, int precision,
	int length, char hnd, char extra_c);
int un_num(int is_negative, int d, char buffer[], int flag, int wid, int precision, int size);
int new_pointer(char buffer[], int d, int length,
        int wid, int flag, char hnd, char extra_c, int buf_pad);

/** CONVERTS **/
int is_print1(char c);
int is_append(char ascii_code, char buffer[], int n);
int is_digit(char c);
long int convert_size(long int m, int size);
long int convert_size1(unsigned long int m, int size);

#endif 

