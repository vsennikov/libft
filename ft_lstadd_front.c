/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:14:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/20 13:53:22 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstadd_front.c
 * @brief Adds a new element at the beginning of a linked list.
 *
 * This function takes a pointer to the first element of a linked list and
 * a new element to be added. It inserts the new element at the beginning
 * of the list.
 *
 * @param lst A double pointer to the first element of the list.
 * @param new A pointer to the new element to be added to the list.
 *
 * @note If either `lst` or `new` is NULL, the function does nothing.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
