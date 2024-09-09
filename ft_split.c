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
			res_size++;
		i++;
	}
	res = (char **)malloc((res_size + 2) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[res_size + 2] = 0;
	return (res);
}

void	free_arr(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
	{
		free(res[i]);
		i++;
	}
	free(res);
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
			{
				free_arr(res);
				return (NULL);
			}
			res[j] = temp;
			j++;
			start_pos = i + 1;
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = create_arr(s, c);
	if (res == NULL)
		return (NULL);
	res = fullfill_arr(s, c, res);
	if (res == NULL)
		return (NULL);
	return (res);
}
