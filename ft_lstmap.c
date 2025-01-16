/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:16:36 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/19 12:15:52 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstmap.c
 * @brief Implementation of a function to map a function over a linked list.
 *
 * This file contains the implementation of the ft_lstmap function, which
 * applies a function to each element of a linked list and creates a new
 * list with the results. It also includes several helper functions for
 * handling errors and cleaning up memory.
 */

/**
 * @brief Deletes content and clears the list.
 *
 * @param del Function to delete the content.
 * @param content The content to be deleted.
 * @param start_lst The starting list to be cleared.
 * @return Always returns NULL.
 */
static void *del_c_lst(void (*del)(void *), void *content, t_list *start_lst);

/**
 * @brief Clears the list.
 *
 * @param start_lst The starting list to be cleared.
 * @param del Function to delete the content.
 * @return Always returns NULL.
 */
static void *del_lst(t_list *start_lst, void (*del)(void *));

/**
 * @brief Deletes content.
 *
 * @param del Function to delete the content.
 * @param content The content to be deleted.
 * @return Always returns NULL.
 */
static void *del_con(void (*del)(void *), void *content);

/**
 * @brief Applies a function to each element of a linked list and creates a new list.
 *
 * This function iterates over the given linked list `lst`, applies the function `f`
 * to each element, and creates a new linked list with the results. If any allocation
 * fails or if `f` returns NULL for any element, the function uses the `del` function
 * to free the allocated memory and returns NULL.
 *
 * @param lst The linked list to be mapped.
 * @param f The function to apply to each element of the list.
 * @param del The function to delete the content of the list in case of an error.
 * @return A new linked list with the results of applying `f` to each element of `lst`,
 *         or NULL if an error occurs.
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

static void	*del_c_lst(void (*del)(void *), void *content, t_list *start_lst)
{
	del(content);
	ft_lstclear(&start_lst, del);
	return (NULL);
}

static void	*del_lst(t_list *start_lst, void (*del)(void *))
{
	ft_lstclear(&start_lst, del);
	return (NULL);
}

static void	*del_con(void (*del)(void *), void	*content)
{
	del(content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_lst;
	t_list	*current;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	content = f(lst->content);
	if (content == NULL)
		return (NULL);
	start_lst = ft_lstnew(content);
	if (start_lst == NULL)
		return (del_con(del, content));
	lst = lst->next;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (content == NULL)
			return (del_lst(start_lst, del));
		current = ft_lstnew(content);
		if (current == NULL)
			return (del_c_lst(del, content, start_lst));
		ft_lstadd_back(&start_lst, current);
		lst = lst->next;
	}
	return (start_lst);
}
