/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:41:00 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:29:20 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (dest_str == NULL && src_str == NULL)
		return (dest_str);
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
