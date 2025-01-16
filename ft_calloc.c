/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:54:05 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/28 19:35:45 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = (unsigned char *)malloc(nitems * size);
	if (arr == NULL)
		return (NULL);
	while (i != nitems * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
