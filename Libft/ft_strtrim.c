/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:37:22 by student           #+#    #+#             */
/*   Updated: 2020/11/22 19:45:11 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left;
	char	*s2;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, 1));
	left = (char*)&s1[i];
	len = ft_strlen(left);
	while (s1[len + i - 1] && ft_strchr(set, s1[len + i - 1]))
		len--;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(s2, left, (len + 1));
	s2[len] = '\0';
	return (s2);
}
