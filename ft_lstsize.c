/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:14:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 16:17:22 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstsize - Counts the number of elements in a linked list.
 * @lst: The beginning of the linked list.
 *
 * This function traverses the linked list starting from the node pointed to
 * by @lst and counts the number of nodes in the list. It returns the total
 * number of nodes found.
 *
 * Return: The number of elements in the linked list. If the list is empty,
 *         the function returns 0.
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
