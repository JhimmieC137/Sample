#include "main.h"

/**
 * print_string - Displays strings 
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: Size specifier
 * Return: Amount of characters printed successfully 
 */

int print_string(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffr);
	UNUSED(curr_flags);
	UNUSED(prnt_len);
	UNUSED(precision);
	UNUSED(arg_sz_spf);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (prnt_len > len)
	{
		if (curr_flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = prnt_len - len; i > 0; i--)
				write(1, " ", 1);
			return (prnt_len);
		}
		else
		{
			for (i = prnt_len - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (prnt_len);
		}
	}

	return (write(1, str, len));
}