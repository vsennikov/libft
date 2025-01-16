/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:27:46 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/20 17:50:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Splits a string into an array of substrings based on a delimiter character.
 *
 * This function takes a string `s` and a delimiter character `c`, and splits the string
 * into an array of substrings, where each substring is a segment of the original string
 * that is separated by the delimiter character. The resulting array is dynamically allocated
 * and must be freed by the caller.
 *
 * Supporting functions:
 * - `count_words`: Counts the number of words in the input string separated by the delimiter.
 * - `malloc_word`: Allocates memory for a single word and copies it from the input string.
 * - `free_words`: Frees the memory allocated for the array of substrings in case of an error.
 *
 * @param s The input string to be split.
 * @param c The delimiter character used to split the string.
 * @return A pointer to an array of substrings, or NULL if memory allocation fails.
 *         If the input string consists entirely of delimiter characters, an array
 *         containing a single NULL pointer is returned.
 */
char	**ft_split(char const *s, char c);

static char	**create_arr(char const *s, char c)
{
	char	**res;
	int		i;
	int		res_size;

	res_size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			res_size++;
		}
		if (s[i] != '\0')
			i++;
	}
	res = (char **)ft_calloc((res_size + 2), sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[res_size + 1] = 0;
	return (res);
}

static void	*free_arr(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**fullfill_arr(char const *s, char c, char **res)
{
	int		start_pos;
	int		i;
	char	*temp;
	int		j;

	i = 0;
	start_pos = 0;
	j = 0;
	while (i <= (int)ft_strlen((char *)s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			temp = ft_substr(s, start_pos, i - start_pos);
			if (temp == NULL)
				return (free_arr(res));
			res[j++] = temp;
			while (i < (int)ft_strlen((char *)s) && s[i] == c && s[i + 1] == c)
				i++;
			start_pos = i + 1;
		}
		if (s[i] == '\0')
			break ;
		++i;
	}
	return (res);
}

static char	**arr_of_delim(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	char	*trimed;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (i == (int)ft_strlen((char *) s))
		return (arr_of_delim());
	trimed = ft_strtrim(s, &c);
	if (trimed == NULL)
		return (NULL);
	res = create_arr(trimed, c);
	if (res == NULL)
	{
		free(trimed);
		return (NULL);
	}
	res = fullfill_arr(trimed, c, res);
	free(trimed);
	if (res == NULL)
		return (NULL);
	return (res);
}
