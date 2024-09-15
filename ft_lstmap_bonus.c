/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:16:36 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/15 16:21:36 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*init_start_lst(t_list *lst, void *(*f)(void *))
{
	t_list	*start_lst;

	start_lst = malloc(sizeof(t_list));
	if (start_lst == NULL)
		return (NULL);
	start_lst->content = lst->content;
	f(start_lst->content);
	start_lst->next = lst->next;
	lst = lst->next;
	return (start_lst);
}

t_list	*init_c_l(t_list *l, t_list *s, void *(*f)(void *))
{
	t_list	*current;

	current = malloc(sizeof(t_list));
	if (current == NULL)
		return (NULL);
	current->content = l->content;
	f(current->content);
	current->next = l->next;
	s->next = current;
	l = l->next;
	return (current);
}

t_list	*fulfill_c(t_list *lst, t_list *current, void *(*f)(void *))
{
	current = malloc(sizeof(t_list));
	if (current == NULL)
		return (NULL);
	current->content = lst->content;
	f(current->content);
	current->next = lst->next;
	lst = lst->next;
	return (current);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_lst;
	t_list	*current;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start_lst = init_start_lst(lst, f);
	if (start_lst == NULL)
		return (NULL);
	current = init_c_l(lst, start_lst, f);
	if (current == NULL)
	{
		ft_lstdelone(start_lst, del);
		return (NULL);
	}
	while (lst != NULL)
	{
		current = fulfill_c(lst, current, f);
		if (current == NULL)
		{
			ft_lstclear(&start_lst, del);
			return (NULL);
		}
	}
	return (start_lst);
}
