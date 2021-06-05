/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:05:28 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 15:22:20 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*start;

	if (lst && new)
	{
		start = (*lst);
		if (start != NULL)
		{
			while (start->next)
				start = start->next;
			start->next = new;
		}
		else
			(*lst) = new;
	}
}
