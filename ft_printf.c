/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:58:57 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:26 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_printf.c
 * @brief Custom implementation of the printf function.
 *
 * This file contains the implementation of a custom printf function named ft_printf.
 * It supports various format specifiers to print different types of data.
 *
 * Supporting Functions:
 * - static int write_char(int c): Writes a single character to the standard output.
 * - int write_str(char *str): Writes a string to the standard output.
 * - static int choose_func(char c, va_list ap): Chooses the appropriate function to handle the format specifier.
 *
 * Supported Format Specifiers:
 * - %c: Character
 * - %s: String
 * - %%: Percent sign
 * - %d, %i: Signed decimal integer
 * - %u: Unsigned decimal integer
 * - %x: Unsigned hexadecimal integer (lowercase)
 * - %X: Unsigned hexadecimal integer (uppercase)
 * - %p: Pointer address
 *
 * @param format The format string containing the text to be written and format specifiers.
 * @param ... Additional arguments specifying the data to be printed.
 * @return The total number of characters written, or -1 if an error occurs.
 */

static int	write_char(int c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write_char((int)str[i]);
		i++;
	}
	return (i);
}

static int	choose_func(char c, va_list ap)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += write_char(va_arg(ap, int));
	else if (c == 's')
		j += write_str(va_arg(ap, char *));
	else if (c == '%')
		j += write_char('%');
	else if (c == 'd' || c == 'i')
		j += ft_putnbr_decimal(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		j += ft_putnbr_add(va_arg(ap, unsigned long), "0123456789abcdef");
	else
	{
		j += write_char('%');
		j += write_char(c);
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	va_start(ap, format);
	i = 0;
	counter = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			counter += choose_func(format[++i], ap);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}
