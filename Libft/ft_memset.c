/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:56:41 by student           #+#    #+#             */
/*   Updated: 2020/11/24 22:10:50 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char*)b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
