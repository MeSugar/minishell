/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:40:17 by student           #+#    #+#             */
/*   Updated: 2020/11/22 20:26:42 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int			len;
	long int	i;

	i = n;
	len = 0;
	if (n == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		len = 1;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static char	*negative(char *str, long int n, int length)
{
	str[0] = '-';
	n = -n;
	str[length] = '\0';
	while (--length >= 1)
	{
		str[length] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*s;
	long int	nbr;
	int			len;

	nbr = n;
	len = ft_size(nbr);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	if (nbr < 0)
		return (negative(s, nbr, len));
	s[len] = '\0';
	while (--len >= 0)
	{
		s[len] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (s);
}
