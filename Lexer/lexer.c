#include "shelly.h"

int comands_counter(char *line)
{
    int i;
    int quotes;
    int dquotes;
    int comands;

    if (!line)
        return (0);
    i = -1;
    comands = 1;
    quotes = 0;
    dquotes = 0;
    while (line[++i])
    {
        if (line[i] == '\'' && !quotes && !dquotes && line[i - 1] != '\\')
            quotes = 1;
        else if (line[i] == '\'' && quotes && !dquotes)
            quotes = 0;
        else if (line[i] == '\"' && !dquotes && !quotes && line[i - 1] != '\\')
            dquotes = 1;
        else if (line[i] == '\"' && dquotes && !quotes && line[i - 1] != '\\')
            dquotes = 0;
        else if (line[i] == ';' && !quotes && !dquotes)
            comands++;
    }
    dquotes = 0;
    if (!line[i] && (quotes || dquotes))
        return (-1);
    // printf("comands: %d\n", comands);
    return (comands);
}

char *backslash(char *line, int *i)
{
    char *prev_str;
	char *next_str;
	char *output;

    prev_str = malloc(sizeof(char) * (*i));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(prev_str, next_str);
	free(line);
    // printf("out: %s\n", output);
    return (output);
}

char *quote(char *line, int *i)
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
        if (line[*i] == '\'' )
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
        if (line[*i] == '\\' && (line[*i + 1] == '\\' || line[*i + 1] == '\''))
            line = backslash(line, i);
		}
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
    return (output);
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
        if (line[*i] == '\"')
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
		}
        if (line[*i] == '\\' && (line[*i + 1] == '\"' || line[*i + 1] == '\\'))
            line = backslash(line, i);
            
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
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
        if (line[i] == '\'')
            line = quote(line, &i);
        if (line[i] == '\"')
            line = dquote(line, &i);
        if (line[i] == '\\')
            line = backslash(line, &i);
        // printf("line: %s\n", line);
    }
	printf("%s\n", line);
	return (0);
}