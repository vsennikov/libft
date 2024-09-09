/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:46:24 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 18:06:00 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*uc_str1;
	unsigned char	*uc_str2;

	uc_str1 = (unsigned char *)str1;
	uc_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (*uc_str1 == *uc_str2 && n - 1 != 0)
	{
		uc_str1++;
		uc_str2++;
		n--;
	}
	return (*uc_str1 - *uc_str2);
}
