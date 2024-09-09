/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_functns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:19 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 13:31:44 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	int		*arr;
	size_t	i;

	i = 0;
	arr = (int *)malloc(nitems * size);
	if (arr == NULL)
		return (NULL);
	while (i != size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
		i++;
	res = (char *)malloc(i * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
