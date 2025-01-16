/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:57:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:38:18 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_itoa.c
 * @brief Converts an integer to a null-terminated string.
 *
 * This file contains the implementation of the ft_itoa function, which converts
 * an integer to a null-terminated string. It also includes two supporting
 * static functions: calculate_size and fullfill_itoa.
 *
 * @details
 * The ft_itoa function allocates memory for the resulting string and handles
 * negative numbers by adding a '-' sign at the beginning of the string.
 *
 * Supporting Functions:
 * - calculate_size: Calculates the number of characters needed to represent
 *   the integer, including the sign if the number is negative.
 * - fullfill_itoa: Fills the allocated string with the appropriate characters
 *   representing the integer.
 *
 * @param n The integer to be converted to a string.
 * @return A pointer to the null-terminated string representing the integer.
 *         Returns NULL if memory allocation fails.
 */
static int	calculate_size(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fullfill_itoa(char *res, long n, int minus, int size)
{
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	if (minus)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		j;
	int		minus;
	long	numb;

	j = calculate_size(n) + 1;
	minus = 0;
	numb = n;
	if (numb < 0)
	{
		minus = 1;
		numb *= -1;
	}
	res = (char *)malloc((j) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[--j] = '\0';
	fullfill_itoa(res, numb, minus, j);
	return (res);
}
