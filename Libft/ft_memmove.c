/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:46:55 by student           #+#    #+#             */
/*   Updated: 2020/11/24 22:08:30 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	j;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (!s1 && !s2)
		return (0);
	if (s2 < s1)
	{
		while (len)
		{
			len--;
			s1[len] = s2[len];
		}
		return (s1);
	}
	j = 0;
	while (j < len)
	{
		s1[j] = s2[j];
		j++;
	}
	return (s1);
}
