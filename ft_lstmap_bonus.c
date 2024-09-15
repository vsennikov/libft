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

void	*del_con_and_lst(void (*del)(void *), void	*content, t_list *start_lst)
{
	del(content);
	ft_lstclear(&start_lst, del);
	return (NULL);
}

void	*del_lst(t_list *start_lst, void (*del)(void *))
{
	ft_lstclear(&start_lst, del);
	return (NULL);
}

void	*del_con(void (*del)(void *), void	*content)
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
			return (del_con_and_lst(del, content, start_lst));
		ft_lstadd_back(&start_lst, current);
		lst = lst->next;
	}
	return (start_lst);
}
