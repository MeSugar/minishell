/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:30:04 by gdelta            #+#    #+#             */
/*   Updated: 2020/11/26 00:07:48 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!(i = ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack && len >= i && len--)
	{
		if (ft_strncmp(haystack, needle, i) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
