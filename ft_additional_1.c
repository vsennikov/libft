/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:53:03 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 13:31:02 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*res;

	i1 = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(i1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1] != '\0')
	{
		res[i2] = s1[i1];
		i2++;
		i1++;
	}
	i1 = 0;
	while (s2[i1] != '\0')
	{
		res[i2] = s2[i1];
		i2++;
		i1++;
	}
	res[i2] = '\0';
	return (res);
}

int	part_of_set(char const *set, char ch)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_pos;
	int		last_pos;
	char	*res;

	start_pos = 0;
	while (part_of_set(set, s1[start_pos]) == 1)
		start_pos++;
	last_pos = (int) ft_strlen((char *)s1) - 1;
	while (part_of_set(set, s1[last_pos]) == 1)
		last_pos--;
	res = ft_substr(s1, start_pos, (last_pos - start_pos) + 1);
	return (res);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	res = (char *)malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
