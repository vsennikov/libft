/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:16:13 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 16:17:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstiter.c
 * @brief Applies a function to each element of a linked list.
 *
 * This function iterates over each element of the linked list pointed to by
 * `lst` and applies the function `f` to the content of each element.
 *
 * @param lst A pointer to the first element of the linked list.
 * @param f A function pointer to the function to be applied to each element's content.
 *
 * @note If either `lst` or `f` is NULL, the function does nothing.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
