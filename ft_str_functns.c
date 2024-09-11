/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:51:35 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 18:00:00 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	to_copy;
	size_t	dest_size;

	j = 0;
	dest_size = ft_strlen(dst);
	i = dest_size;
	if (size <= dest_size)
		return (ft_strlen((char *)src) + size);
	else
		to_copy = size - ft_strlen(dst) - 1;
	while (j != to_copy)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_size + ft_strlen((char *)src));
}

char	*ft_strchr(const char *str, int search_str)
{
	int	i;
	int	size;

	i = 0;
	size = (int) ft_strlen((char *)str) + 1;
	while (i <= size)
	{
		if (str[i] == search_str)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = (int) ft_strlen((char *) str) + 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
