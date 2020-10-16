/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:44:25 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/08 15:50:04 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *start;

	start = lst;
	while (lst && f && del)
	{
		f(lst->content);
		if (!(new = malloc(sizeof(t_list))))
			del(new);
		new->content = lst->content;
		lst = lst->next;
		ft_lstadd_back(&start, new);
	}
	return (new);
}
