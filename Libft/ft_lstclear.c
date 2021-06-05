/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:53:51 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/04 00:04:39 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list_to_free;
	t_list *tmp;

	if (!del || !lst)
		return ;
	list_to_free = *lst;
	while (list_to_free)
	{
		del(list_to_free->content);
		tmp = list_to_free->next;
		free(list_to_free);
		list_to_free = tmp;
	}
	*lst = 0;
}
