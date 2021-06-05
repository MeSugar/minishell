/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:40:15 by gdelta            #+#    #+#             */
/*   Updated: 2020/11/24 19:29:47 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static int	word_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	*cleaner(char **arr, int words)
{
	int		i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		clmn;

	if (!s)
		return (0);
	if (!(arr = (char**)malloc(sizeof(char*) * (word_counter(s, c) + 1))))
		return (0);
	i = 0;
	clmn = 0;
	while (clmn < word_counter(s, c) && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		arr[clmn] = ft_substr(s, i, word_len(&s[i], c));
		if (arr[clmn] == 0)
			return (cleaner(arr, clmn));
		while (s[i] && s[i] != c)
			i++;
		clmn++;
	}
	arr[clmn] = 0;
	return (arr);
}
