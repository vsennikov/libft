/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:55:18 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 15:49:21 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr - Allocates and returns a substring from the string 's'.
 * 
 * @s: The string from which to create the substring.
 * @start: The start index of the substring in the string 's'.
 * @len: The maximum length of the substring.
 * 
 * Return: The substring. NULL if the allocation fails.
 * 
 * Description: This function allocates memory and returns a substring
 * from the string 's'. The substring begins at index 'start' and is of
 * maximum size 'len'. If 'start' is greater than the length of 's', the
 * function returns an empty string. If 'len' is greater than the length
 * of the substring starting from 'start', the function returns the
 * substring from 'start' to the end of 's'.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	real_size;

	i = 0;
	real_size = ft_strlen((char *) s);
	if ((start > real_size - 1 && real_size != 0))
		len = 0;
	else if (real_size == 0 && start > real_size)
		len = 0;
	else
		real_size = ft_strlen((char *) s + start);
	if (real_size < len)
		len = real_size;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
