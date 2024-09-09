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

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

extern	size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i1;
	size_t	i2;
	size_t	size_dst;

	i1 = 0;
	i2 = 0;
	while (dst[i1] != '\0')
		i1++;
	size_dst = i1;
	while (src[i2] != '\0' && i1 < size - 1 && size != 0)
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	i2 = 0;
	while (src[i2] != '\0')
		i2++;
	return (size_dst + i2);
}

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != search_str)
			i++;
		else
			break ;
	}
	return ((char *)(str + i));
}

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*pnt;

	i = (int) ft_strlen((char *) str) + 1;
	while (i >= 0)
	{
		if (str[i] == c)
		{
			pnt = (char *)str + i;
			break ;
		}
		i--;
	}
	if (i < 0)
		return (0);
	return (pnt);
}
