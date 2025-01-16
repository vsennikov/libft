/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:15:20 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/24 17:48:53 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstadd_back - Adds a new element at the end of a linked list.
 * @lst: A pointer to the first element of the list.
 * @new: The new element to be added to the list.
 *
 * This function adds the element 'new' at the end of the list pointed to by 'lst'.
 * If 'lst' is NULL, the function does nothing. If the list is empty (i.e., *lst is NULL),
 * the new element becomes the first element of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = ft_lstlast(*lst);
	current->next = new;
}
