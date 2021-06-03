#ifndef UTILS_H
# define UTILS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// GNL utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_calloc(size_t size);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);

#endif