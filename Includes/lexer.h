#ifndef LEXER_H
# define LEXER_H

// typedef struct	s_token
// {
// 	char *content;
// 	struct s_token *next;
// }				t_token;

int lexer(char *line, char **envp);

#endif