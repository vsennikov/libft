/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:56:21 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:11:47 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is part of a given set of characters.
 *
 * @param set The set of characters to check against.
 * @param ch The character to check.
 * @return 1 if the character is part of the set, 0 otherwise.
 */
static int	part_of_set(char const *set, char ch)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Trims the characters from the beginning and end of a string that are part of a given set.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim from the string.
 * @return A new string with the characters from the set trimmed from the beginning and end.
 *         The returned string should be freed by the caller.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_pos;
	int		last_pos;
	char	*res;

	start_pos = 0;
	while (part_of_set(set, s1[start_pos]) == 1)
		start_pos++;
	last_pos = (int) ft_strlen((char *)s1) - 1;
	while (part_of_set(set, s1[last_pos]) == 1)
		last_pos--;
	res = ft_substr(s1, start_pos, (last_pos - start_pos) + 1);
	return (res);
}
