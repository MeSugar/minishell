/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:19:58 by student           #+#    #+#             */
/*   Updated: 2020/11/24 00:50:20 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	len = 0;
	if (!dstsize || dstsize <= i)
		return (dstsize + j);
	while (src[len] && (i + len) < (dstsize - 1))
	{
		dst[i + len] = src[len];
		len++;
	}
	dst[i + len] = '\0';
	return (i + j);
}
