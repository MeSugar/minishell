/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:58:29 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/03 22:27:32 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *list;

	list = lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		return (list);
	}
	return (0);
}
