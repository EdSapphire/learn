#include "main.h"

/**
 * con_print - A function that prints an argument based on its type
 * @format: Formatted string
 * @view: List of arguments
 * @d: Argument
 * @buffer: Buffer array to handle print.
 * @flag: Calculates flags
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int con_print(const char *format, int *d, va_list view, char buffer[],
	int flag, int wid, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*d] == format_types[i].format)
			return (format_types[i].fn(view, buffer, flag, wid, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*d] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*d - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*d);
			while (format[*d] != ' ' && format[*d] != '%')
				--(*d);
			if (format[*d] == ' ')
				--(*d);
			return (1);
		}
		unknow_len += write(1, &format[*d], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
