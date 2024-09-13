/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:27:46 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 13:31:53 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**create_arr(char const *s, char c)
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
	res = (char **)malloc((res_size + 2) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[res_size + 1] = 0;
	return (res);
}

void	*free_arr(char **res)
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

char	**fullfill_arr(char const *s, char c, char **res)
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
			res[j] = temp;
			j++;
			while (s[i] == c && s[i + 1] == c)
				i++;
			start_pos = i + 1;
		}
		i++;
	}
	return (res);
}

char	**arr_of_delim(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = malloc(sizeof(char));
	if (res[0] == NULL)
	{
		free(res);
		return (NULL);
	}
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
	{
		res = arr_of_delim();
		return (res);
	}
	trimed = ft_strtrim(s, &c);
	res = create_arr(trimed, c);
	if (res == NULL)
		return (NULL);
	res = fullfill_arr(trimed, c, res);
	free(trimed);
	return (res);
}
