#include "main.h"

/**
 * var_ptr - Prints the value of a pointer variable
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculate flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */
int var_ptr(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	char extra_c = 0, hnd = ' ';
	int d = BUFF_SIZE - 2, length = 2, buf_pad = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[d--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		hnd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;

	d++;

	return (new_pointer(buffer, d, length,
		wid, flag, hnd, extra_c, buf_pad));
}

/**
 * non_chars - A function that prints ascii codes in hexa of non printable chars
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: Calculates flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars
 */
int non_chars(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	int n = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[n] != '\0')
	{
		if (is_print1(str[n]))
			buffer[n + offset] = str[n];
		else
			offset += is_append(str[n], buffer, n + offset);

		n++;
	}

	buffer[n + offset] = '\0';

	return (write(1, buffer, n + offset));
}

/**
 * _reverse - A function that prints reverse string.
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: Calculate flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Numbers of chars.
 */

int _reverse(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	char *str;
	int n, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
	{
		for (n = n - 1; n >= 0; n--)
		{
			char z = str[n];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * rot13_str - A function that print a string in rot13.
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: Calculate flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Numbers of chars
 */
int rot13_str(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
