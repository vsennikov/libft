/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:03:14 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/06 13:31:10 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	write_from_end(char *str, int index, int fd)
{
	while (index >= 0)
	{
		write(fd, &str[index], sizeof(char));
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;
	int		i;
	char	str[11];

	i = 0;
	numb = n;
	if (numb == 0)
		write(fd, "0", sizeof(char));
	else if (numb < 0)
	{
		numb *= -1;
		write(fd, "-", sizeof(char));
	}
	while (numb > 0)
	{
		str[i] = numb % 10 + '0';
		numb /= 10;
		i++;
	}
	str[i] = '\0';
	write_from_end(str, i - 1, fd);
}
