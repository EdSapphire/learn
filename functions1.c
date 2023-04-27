#include "main.h"

/**
 * int_num - unsigned number to be printed
 * @type: List arguments
 * @buffer: Buffer array
 * @flag: Calculates flags
 * @wid: Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */

int int_num(va_list type, char buffer[], int flag,
		int wid, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int m = va_arg(type, unsigned long int);

	m = convert_size1(m, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (m > 0)
	{
		buffer[i--] = (m % 10) + '0';
		m /= 10;
	}

	i++;

	return (un_num(0, i, buffer, flag, wid, precision, size));
}

/**
 * int_octal - Prints an unsigned number in octal notation
 * @type: List 
 * @buffer: Buffer array to handle print
 * @flag: Calculate flags
 * @wid: The Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */
int int_octal(va_list type, char buffer[], int flag,
		int wid, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int m = va_arg(type, unsigned long int);
	unsigned long int init_num = m;

	UNUSED(wid);

	m = convert_size1(m, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (m > 0)
	{
		buffer[i--] = (m % 8) + '0';
		m /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (un_num(0, i, buffer, flag, wid, precision, size));
}

/**
 * hex_decimal - A function that prints unsigned number in hexadecimal notation
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates flags
 * @wid: The Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */

int hex_decimal(va_list type, char buffer[], int flag,
		int wid, int precision, int size)
{
	return (hex_low(type, "0123456789abcdef", buffer,
		flag, 'x', wid, precision, size));
}

/**
 * hexa_upper1 - Prints an unsigned number in upper hexadecimal notation
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @wid: The width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int hexa_upper1(va_list type, char buffer[], int flag,
		int wid, int precision, int size)
{
	return (hex_low(type, "0123456789ABCDEF", buffer,
		flag, 'X', wid, precision, size));
}

/**
 * hex_low - Prints a hexadecimal number in lower notation
 * @type: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag: Calculates flags
 * @flag_ch: Calculates flags
 * @wid: The width
 * @precision: Precision specifier
 * @size: Size specifier
 * 
 * Return: Number of chars.
 */
int hex_low(va_list type, char map_to[], char buffer[],
	int flag, char flag_ch, int wid, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int m = va_arg(type, unsigned long int);
	unsigned long int init_num = m;

	UNUSED(wid);

	m = convert_size1(m, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (m > 0)
	{
		buffer[i--] = map_to[m % 16];
		m /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (un_num(0, i, buffer, flag, wid, precision, size));
}
