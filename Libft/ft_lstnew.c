/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:16:50 by gdelta            #+#    #+#             */
/*   Updated: 2020/11/29 18:32:09 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(t_list))))
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}
