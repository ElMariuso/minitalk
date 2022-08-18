/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:39:36 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:56:27 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_con;

	if (!lst || !f)
		return (0);
	new_con = ft_lstnew(f(lst->content));
	if (!new_con)
		return (0);
	new_lst = new_con;
	lst = lst->next;
	while (lst)
	{
		new_con = ft_lstnew(f(lst->content));
		if (!new_con)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_con);
	}
	return (new_lst);
}
