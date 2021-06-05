/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:42:23 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/04 01:38:12 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *out;

	if (!lst || !f || !del)
		return (0);
	out = 0;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&out, del);
			return (0);
		}
		ft_lstadd_back(&out, tmp);
		lst = lst->next;
	}
	return (out);
}
