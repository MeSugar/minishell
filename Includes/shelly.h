#ifndef SHELLY_H
# define SHELLY_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "lexer.h"


int			get_next_line(int fd, char **line);


#endif