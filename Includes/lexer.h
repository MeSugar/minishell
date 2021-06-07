#ifndef LEXER_H
# define LEXER_H

// token types
// # define CHAR 10
// # define QUOTE 11
// # define DQUOTE 12
// # define PIPE 13
// # define SEMICOLON 14
// # define GREATER 15
// # define LESSER 16

typedef struct	s_token
{
	char *content;
	struct s_token *next;
}				t_token;

int lexer(char *line);

#endif