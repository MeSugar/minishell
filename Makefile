NAME		=	shelly

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

INCLUDES	=	./Includes

# LIBFT_PATH	=	./Libft

# LIBFT		=	./Libft/libft.a

SRCS		=	main.c Utils/get_next_line.c Utils/get_next_line_utils.c

all : $(NAME)

$(NAME) : $(SRCS)
		@$(CC) -g -o $(NAME) $(CFLAGS) $(SRCS) -I $(INCLUDES)

clean :
		@rm -rf Utils/*.o

fclean : clean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re