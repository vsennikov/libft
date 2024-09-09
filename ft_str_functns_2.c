/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functns_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:11:23 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/09 14:49:47 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (i == n)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && i < n - 1)
	{
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	else
		return (str1[i] - str2[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i != len)
	{
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && i != len && little[j] != '\0')
			{
				i++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i - j]);
			else
				j = 0;
		}
		else
			i++;
	}
	return (NULL);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 0;
	result = 0;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (minus)
		result *= -1;
	return (result);
}
