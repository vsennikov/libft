/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:13:19 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 17:53:59 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstnew.c
 * @brief Creates a new list node with the given content.
 *
 * This function allocates memory for a new list node and initializes its
 * content with the provided value. The next pointer of the new node is set
 * to NULL.
 *
 * @param content The content to be stored in the new list node.
 * @return A pointer to the newly created list node, or NULL if memory
 * allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
