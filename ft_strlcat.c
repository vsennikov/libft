/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:42:52 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:57:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (j != to_copy && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_size + ft_strlen((char *)src));
}
