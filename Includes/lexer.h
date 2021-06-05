#ifndef LEXER_H
# define LEXER_H

typedef struct	s_token
{
	int type;
	struct s_token *next;
}				t_token;


typedef struct	s_lex
{
	int count;
	t_token *toklist;
}				t_lex;

void lexer(char *line, t_lex *lexer);

#endif