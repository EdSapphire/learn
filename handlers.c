#include "main.h"

/** 
 * _handler - A function that prints a string
 * @c: String to print
 * @buffer: Buffer that handle print
 * @flag: Calculate flag
 * @wid: The width
 * @precision: The precision
 * @size: The size
 *
 * Return: Chars.
 */
int _handler(char c, char buffer[], int flag, int wid, int precision, int size)
{
	int i = 0;
	char hnd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
		hnd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';
	
	if (wid > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (i = 0; i < wid - 1; i++)
			buffer[BUFF_SIZE - i - 2] = hnd;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i - 1], wid - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], wid - 1) + write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * _numbers - Prints a string
 * @is_negative: List of arguments
 * @d: Char type
 * @buffer: Buffer to handle print
 * @flag:  Calculates flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */
int _numbers(int is_negative, int d, char buffer[],
	int flag, int wid, int precision, int size)
{
	int length = BUFF_SIZE - d - 1;
	char hnd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		hnd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (buf_num(d, buffer, flag, wid, precision,
		length, hnd, extra_ch));
}

/**
 * buf_num - A function that write a number using a bufffer
 * @d: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @wid: width
 * @precision: Precision specifier
 * @length: Number length
 * @hnd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of chars.
 */
int buf_num(int d, char buffer[],
	int flag, int wid, int precision,
	int length, char hnd, char extra_c)
{
	int i, buf_pad = 1;

	if (precision == 0 && d == BUFF_SIZE - 2 && buffer[d] == '0' && wid == 0)
		return (0);
	if (precision == 0 && d == BUFF_SIZE - 2 && buffer[d] == '0')
		buffer[d] = hnd = ' ';
	if (precision > 0 && precision < length)
		hnd = ' ';
	while (precision > length)
		buffer[--d] = '0', length++;
	if (extra_c != 0)
		length++;
	if (wid > length)
	{
		for (i = 1; i < wid - length + 1; i++)
			buffer[i] = hnd;
		buffer[i] = '\0';
		if (flag & F_MINUS && hnd == ' ')
		{
			if (extra_c)
				buffer[--d] = extra_c;
			return (write(1, &buffer[d], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & F_MINUS) && hnd == ' ')
		{
			if (extra_c)
				buffer[--d] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flag & F_MINUS) && hnd == '0')
		{
			if (extra_c)
				buffer[--buf_pad] = extra_c;
			return (write(1, &buffer[buf_pad], i - buf_pad) +
				write(1, &buffer[d], length - (1 - buf_pad)));
		}
	}
	if (extra_c)
		buffer[--d] = extra_c;
	return (write(1, &buffer[d], length));
}

/**
 * un_num - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @d: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars.
 */
int un_num(int is_negative, int d,
	char buffer[],
	int flag, int wid, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - d - 1, i = 0;
	char hnd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && d == BUFF_SIZE - 2 && buffer[d] == '0')
		return (0);

	if (precision > 0 && precision < length)
		hnd = ' ';

	while (precision > length)
	{
		buffer[--d] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		hnd = '0';

	if (wid > length)
	{
		for (i = 0; i < wid - length; i++)
			buffer[i] = hnd;

		buffer[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[d], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[d], length));
}

/**
 * new_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @d: Index at which the number starts in the buffer
 * @length: Length of number
 * @wid: Wwidth specifier
 * @flag: Flags specifier
 * @hnd: Char representing the padding
 * @extra_c: Char representing extra char
 * @buf_pad: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int new_pointer(char buffer[], int d, int length,
	int wid, int flag, char hnd, char extra_c, int buf_pad)
{
	int i;

	if (wid > length)
	{
		for (i = 3; i < wid - length + 3; i++)
			buffer[i] = hnd;
		buffer[i] = '\0';
		if (flag & F_MINUS && hnd == ' ')
		{
			buffer[--d] = 'x';
			buffer[--d] = '0';
			if (extra_c)
				buffer[--d] = extra_c;
			return (write(1, &buffer[d], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && hnd == ' ')
		{
			buffer[--d] = 'x';
			buffer[--d] = '0';
			if (extra_c)
				buffer[--d] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[d], length));
		}
		else if (!(flag & F_MINUS) && hnd == '0')
		{
			if (extra_c)
				buffer[--buf_pad] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[buf_pad], i - buf_pad) +
				write(1, &buffer[d], length - (1 - buf_pad) - 2));
		}
	}
	buffer[--d] = 'x';
	buffer[--d] = '0';
	if (extra_c)
		buffer[--d] = extra_c;
	
	return (write(1, &buffer[d], BUFF_SIZE - d - 1));
}
