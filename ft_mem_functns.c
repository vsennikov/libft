/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:47:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 17:58:35 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *) str;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '0', n);
}

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char *) dest_str;
	src = (unsigned char *) src_str;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *) dest_str;
	src = (unsigned char *) src_str;
	if (dest == src)
		return (dest);
	else if (dest > src && src + numBytes > dest)
	{
		dest += numBytes;
		src += numBytes;
		while (numBytes != 0)
		{
			*dest = *src;
			dest--;
			src--;
			numBytes--;
		}
	}
	else
		dest = ft_memcpy(dest_str, src_str, numBytes);
	return (dest);
}

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_str;

	i = 0;
	uc_str = (unsigned char *) str;
	while (n != 0)
	{
		if (*uc_str == c)
		{
			return (uc_str);
			break ;
		}
		uc_str++;
		n--;
	}
	return (NULL);
}
