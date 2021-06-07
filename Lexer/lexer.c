#include "shelly.h"

int comands_counter(char *line)
{
    int i;
    int quotes;
    int comands;

    if (!line)
        return (0);
    i = -1;
    comands = 1;
    quotes = 0;
    while (line[++i])
    {
        if ((line[i] == '\'' || line[i] == '\"') && !quotes && line[i - 1] != '\\')
            quotes = 1;
        else if (line[i] == ';' && !quotes)
            comands++;
        else if ((line[i] == '\'' || line[i] == '\"') && quotes && line[i - 1] != '\\')
            quotes = 0;
    }
    if (!line[i] && quotes)
        return (-1);
    return (comands);
}

char *dquote(char *line, int *i)
{
	int frst_quote;
    char *prev_str;
	char *curr_str;
	char *next_str;
	char *output;

	frst_quote = *i;
    prev_str = malloc(sizeof(char) * (*i));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
    while (line[++(*i)])
    {
        if (line[*i] == '\"' && line[*i - 1] != '\\')
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
		}
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
	free(curr_str);
	free(prev_str);
	free(next_str);
    return (output);
}

int lexer(char *line)
{
    int i;
    int ncomands;

    if ((ncomands = comands_counter(line)) == -1)
		return (printf("wrong syntax\n"));
    i = -1;
    while(line[++i])
    {
        if (line[i] == '\"')
            line = dquote(line, &i);
    }
	printf("%s\n", line);
	return (0);
}