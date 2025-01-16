/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:15:59 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 18:28:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstclear.c
 * @brief Contains the implementation of the ft_lstclear function.
 *
 * The ft_lstclear function deletes and frees the given linked list and its content
 * using the function 'del' and free(3). Finally, the pointer to the list is set to NULL.
 *
 * @param lst A pointer to the pointer of the first element of the list.
 * @param del A function pointer to the function used to delete the content of an element.
 *
 * @note If either lst or del is NULL, the function does nothing.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
