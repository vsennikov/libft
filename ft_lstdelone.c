/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:15:36 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 16:52:29 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstdelone.c
 * @brief Deletes a single element from a linked list.
 *
 * This function takes a pointer to a linked list element and a function pointer
 * to a delete function. It applies the delete function to the content of the
 * element and then frees the memory allocated for the element itself.
 *
 * @param lst A pointer to the linked list element to be deleted.
 * @param del A function pointer to a function that takes a void pointer as an
 * argument and frees the content of the linked list element.
 *
 * @note If either `lst` or `del` is NULL, the function does nothing.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
