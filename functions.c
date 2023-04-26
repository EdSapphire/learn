#include "main.h"


/**
 * write_char - Prints a char
 * @type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @wid: Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars
 */
int write_char(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	char c = va_arg(type, int);

	return (_handler(c, buffer, flag, wid, precision, size));
}

/**
 * _string1 - Prints a string
 * @type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates flags
 * @wid: Width.
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */
int _string1(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (wid > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}

	return (write(1, str, length));
}

/**
 * cal_percent - Prints a percent sign
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates flags
 * @wid: Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: No. of chars
 */
int cal_percent(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * new_int - Print int
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: Calculate flags
 * @wid: Width.
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int new_int(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int m;

	n = convert_size1(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	m = (unsigned long int)n;

	if (n < 0)
	{
		m = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (m > 0)
	{
		buffer[i--] = (m % 10) + '0';
		m /= 10;
	}

	i++;

	return (_numbers(is_negative, i, buffer, flag, wid, precision, size));
}

/**
 * _binary - Prints an unsigned number
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates flags
 * @wid: Width.
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Numbers of char printed.
 */
int _binary(va_list type, char buffer[],
	int flag, int wid, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(type, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
