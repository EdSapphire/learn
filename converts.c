#include "main.h"

/**
 * is_print1 - A function that check if a char is printable
 * @c: The char to be checked 
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print1(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * is_append - A function that append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @n: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int is_append(char ascii_code, char buffer[], int n)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[n++] = '\\';
	buffer[n++] = 'x';

	buffer[n++] = map_to[ascii_code / 16];
	buffer[n] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - A function that checks if a char is a digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size - A function that casts a number to a specified size
 * @m: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of m.
 */
long int convert_size(long int m, int size)
{
	if (size == S_LONG)
		return (m);
	else if (size == S_SHORT)
		return ((short)m);

	return ((int)m);
}

/**
 * convert_size1 - A function that casts a number to a specified size
 * @m: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size1(unsigned long int m, int size)
{
	if (size == S_LONG)
		return (m);
	else if (size == S_SHORT)
		return ((unsigned short)m);

	return ((unsigned int)m);
}
