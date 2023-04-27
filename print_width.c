#include "main.h"

/**
 * print_width - A funtion that prints the width
 * @format: Formatted string that prints arguments
 * @i: Argument list
 * @view: Arguments view
 *
 * Return: The width.
 */
int print_width(const char *format, int *i, va_list view)
{
	int curr_i;
	int wid = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			wid *= 10;
			wid += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			wid = va_arg(view, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (wid);
}
