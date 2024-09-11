/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:58:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/09 15:49:07 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calculate_size(long n)
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

void	fullfill_itoa(char *res, long n, int minus, int size)
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
