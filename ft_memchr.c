/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:29 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:43:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*uc_str;

	uc_str = (unsigned char *) str;
	while (n != 0)
	{
		if (*uc_str == (unsigned char) c)
			return (uc_str);
		uc_str++;
		n--;
	}
	return (NULL);
}
