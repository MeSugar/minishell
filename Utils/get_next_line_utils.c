#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	if (!(s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_calloc(size_t size)
{
	char *str;

	str = malloc(size);
	if (str == 0)
		return (0);
	*str = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}