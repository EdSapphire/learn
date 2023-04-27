#include "main.h"

/**
 * calc_precision - A function that calculates the precision
 * @format: Formatted string in which to print the arguments 
 * @i: Argument to be printed
 * @view: Argument list
 *
 * Return: Precision.
 */
int calc_precision(const char *format, int *i, va_list view)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(view, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (precision);
}
