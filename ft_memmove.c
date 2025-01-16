/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:41:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 13:04:16 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *) dest_str;
	src = (unsigned char *) src_str;
	if (dest > src && src + numBytes > dest)
	{
		dest += numBytes - 1;
		src += numBytes - 1;
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
	return (dest_str);
}
