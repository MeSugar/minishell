NAME		=	shelly

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

INCLUDES	=	./Includes

LIBFT_PATH	=	./Libft

LIBFT		=	./Libft/libft.a

SRCS		=	main.c Utils/get_next_line.c \
				Lexer/lexer.c

all : $(NAME)

$(NAME) : $(SRCS)
		@make bonus -C $(LIBFT_PATH)
		@$(CC) -g -o $(NAME) $(CFLAGS) $(SRCS) -I $(INCLUDES) -I $(LIBFT_PATH) $(LIBFT) -lreadline

clean :
		@make -C $(LIBFT_PATH) clean
		@rm -rf Utils/*.o

fclean : clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re