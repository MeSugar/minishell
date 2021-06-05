/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 01:47:31 by student           #+#    #+#             */
/*   Updated: 2020/11/24 21:33:25 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (!*s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
