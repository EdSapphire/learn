#include "main.h"

void print_buffer(char buffer[], int *buff_d);

/**
 * _printf - This is a Printf function
 * @format: format argument
 *
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, print = 0, printed_chars = 0;
	int flag, wid, precision, size, buff_d = 0;
	va_list view;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(view, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_d++] = format[i];
			if (buff_d == BUFF_SIZE)
				print_buffer(buffer, &buff_d);
			
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_d);
			flag = calc_flag(format, &i);
			wid = print_width(format, &i, view);
			precision = calc_precision(format, &i, view);
			size = cal_size(format, &i);
			++i;
			print = con_print(format, &i, view, buffer,
				flag, wid, precision, size);
			if (print == -1)
				return (-1);
			printed_chars += print;
		}
	}

	print_buffer(buffer, &buff_d);

	va_end(view);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_d)
{
        if (*buff_d > 0)
                write(1, &buffer[0], *buff_d);

        *buff_d = 0;
}
