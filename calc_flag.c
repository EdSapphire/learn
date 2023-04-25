#include "main.h"

/**
 * calc_flag - A function that calculate active flags
 * @format: Formatted string that print arguments
 * @i: Input parameter
 *
 * Return: Flag.
 */
int calc_flag(const char *format, int *i)
{
	int n, curr_i;
	int flag = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[curr_i] == FLAGS_CH[n])
			{
				flag |= FLAGS_ARR[n];
				break;
			}
		if (FLAGS_CH[n] == 0)
			break;
	}
	*i = curr_i - 1;

	return (flag);
}

