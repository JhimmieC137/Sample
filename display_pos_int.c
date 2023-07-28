#include "main.h"

/**
 * print_unsigned - Displays unsigned integers
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */

int print_unsigned(va_list types, char buff[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	int z = BUFF_SIZE - 2;
	unsigned long int iter = va_arg(types, unsigned long int);

	iter = convert_size_unsgnd(iter, arg_sz_spf);

	if (iter == 0)
		buff[z--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (iter > 0)
	{
		buff[z--] = (iter % 10) + '0';
		iter /= 10;
	}

	z++;

	return (write_unsgnd(0, z, buff, curr_flags, prnt_len, precision, arg_sz_spf));
}