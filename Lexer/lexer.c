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
    if (line[0] == '|' || line[0] == ';')
        return (-1);
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

    prev_str = malloc(sizeof(char) * (*i + 1));
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
    prev_str = malloc(sizeof(char) * (*i + 1));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
    while (line[++(*i)])
    {
        if (line[*i] == '\'' )
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
        if (line[*i] == '\\' && (line[*i + 1] == '\\' || line[*i + 1] == '\'' || line[*i + 1] == '$'))
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
    prev_str = malloc(sizeof(char) * (*i + 1));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
    while (line[++(*i)])
    {
        if (line[*i] == '\"')
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
		}
        if (line[*i] == '\\' && (line[*i + 1] == '\"' || line[*i + 1] == '\\' || line[*i + 1] == '$'))
            line = backslash(line, i);
            
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
    return (output);
}

char *env(char *line, int *i, char **envp)
{
    int start;
    int j;
    int key_len;
    char *prev_str;
	char *key;
	// char *next_str;
	char *output;

    start = *i;
    if (line[start + 1] != '_' && !ft_isalnum(line[start + 1]))
        return (line);
    prev_str = malloc(sizeof(char) * (*i + 1));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
    while (line[++(*i)])
    {
        if (line[*i] != '_' && !ft_isalnum(line[*i]))
        {
            key = malloc(sizeof(char) * ((*i) - start));
    		key = ft_memcpy(key, line + start + 1, (size_t)((*i) - start - 1));
			break;
        }
    }
    j = -1;
    key_len = ft_strlen(key);
    while (envp[++j])
    {
        if (!ft_strncmp(key, envp[j], key_len) && envp[j][key_len + 1] == '=')
        {
            key = 

            break;
        }
    }
    // printf("%s\n", envp[start]);
	output = ft_strjoin(prev_str, key);
    // printf("env: %s\n", output);
	// next_str = ft_strdup(line + *i + 1);
	// output = ft_strjoin(output, next_str);
	free(line);
    return (output);
}

int lexer(char *line, char **envp)
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
        if (line[i] == '$')
            line = env(line, &i, envp);
        // printf("line: %s\n", line);
    }
	printf("%s\n", line);
	return (0);
}