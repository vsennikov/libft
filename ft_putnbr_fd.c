/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:00:53 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:01:33 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putnbr_fd.c
 * @brief Outputs the integer n to the given file descriptor.
 *
 * This function converts an integer to its string representation and writes it
 * to the specified file descriptor. It handles negative numbers by writing a
 * '-' character before the digits. The function uses a helper function 
 * `write_from_end` to write the digits in the correct order.
 *
 * @param n The integer to be printed.
 * @param fd The file descriptor on which to write.
 *
 * @note The function uses a static helper function `write_from_end` to write
 *       the characters from the end of the string to the beginning.
 *
 * @internal
 * @function write_from_end
 * @brief Writes the characters of a string to a file descriptor in reverse order.
 * 
 * This static helper function is used internally by `ft_putnbr_fd` to write the
 * characters of the number string in the correct order.
 *
 * @param str The string containing the number characters.
 * @param index The index of the last character in the string.
 * @param fd The file descriptor on which to write.
 */
static void	write_from_end(char *str, int index, int fd)
{
	while (index >= 0)
	{
		write(fd, &str[index], sizeof(char));
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;
	int		i;
	char	str[11];

	i = 0;
	numb = n;
	if (numb == 0)
		write(fd, "0", sizeof(char));
	else if (numb < 0)
	{
		numb *= -1;
		write(fd, "-", sizeof(char));
	}
	while (numb > 0)
	{
		str[i] = numb % 10 + '0';
		numb /= 10;
		i++;
	}
	str[i] = '\0';
	write_from_end(str, i - 1, fd);
}
