#include "shelly.h"

static int	line_check(char *line, t_info *info)
{
    int i;
    int quotes;
    int dquotes;

    // if (*line == '\0')
    //     return ;
    i = -1;
    quotes = 0;
    dquotes = 0;
    if (line[0] == '|' || line[0] == ';' || line[0] == '\\')
		return (print_error("Wrong syntax\n", info));
	info->elements++;
    while (line[++i])
    {
        if (line[i] == '\'' && !quotes && !dquotes)
            quotes = 1;
        else if (line[i] == '\'' && quotes && !dquotes)
            quotes = 0;
        else if (line[i] == '\"' && !dquotes && !quotes)
            dquotes = 1;
        else if (line[i] == '\"' && dquotes && !quotes)
            dquotes = 0;
        else if ((line[i] == '|' || line[i] == '>' || line[i] == '<') && !quotes && !dquotes)
            info->elements++;
    }
    // dquotes = 0;
    if ((!line[i] && (quotes || dquotes)) || skip_whitespaces(i, line))
		return (print_error("Wrong syntax\n", info));
    // printf("elements: %d\n", info->elements);
	return (0);
}

// char *backslash(char *line, int *i)
// {
//     char *prev_str;
// 	char *next_str;
// 	char *output;

//     prev_str = malloc(sizeof(char) * (*i + 1));
//     prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
// 	next_str = ft_strdup(line + *i + 1);
// 	output = ft_strjoin(prev_str, next_str);
// 	free(line);
//     // printf("out: %s\n", output);
//     return (output);
// }

char *envi(char *line, int *i, char **envp)
{
    int start;
    int j;
    char *prev_str;
	char *curr_str;
	char *key;
	char *next_str;
	char *output;

    start = *i;
    if (line[start + 1] != '_' && !ft_isalnum(line[start + 1]))
        return (line);
    prev_str = malloc(sizeof(char) * (*i + 1));
    prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
    while (line[++(*i)])
    {
        if ((line[*i + 1] != '_' && !ft_isalnum(line[*i + 1])) || (line[*i] != '_' && !ft_isalnum(line[*i])))
        {
            key = malloc(sizeof(char) * ((*i) - start + 1));
    		key = ft_memcpy(key, line + start + 1, (size_t)((*i) - start));
			break ;
        }
    }
	next_str = strdup(line + *i + 1);
	// printf("next str is: %s\n", next_str);
    j = -1;
	curr_str = 0;
    while (envp[++j])
    {
        if (!ft_strncmp(key, envp[j], ft_strlen(key)) && envp[j][ft_strlen(key)] == '=')
        {
            curr_str = malloc(sizeof(char) * (ft_strlen(envp[j]) - ft_strlen(key)) + 1);
			curr_str = ft_memcpy(curr_str, envp[j] + ft_strlen(key) + 1, ft_strlen(envp[j]) - ft_strlen(key) + 1);
            break ;
        }
    }
	if (!curr_str)
		return (line);
	output = ft_strjoin(prev_str, curr_str);
	output = ft_strjoin(output, next_str);
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
        // if (line[*i] == '\\' && (line[*i + 1] == '\\' || line[*i + 1] == '\'' || line[*i + 1] == '$'))
        //     line = backslash(line, i);
		}
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
    return (output);
}

char *dquote(char *line, int *i, char **envp)
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
		if (line[*i] == '$')
			line = envi(line, i, envp);
        // if (line[*i] == '\\' && (line[*i + 1] == '\"' || line[*i + 1] == '\\' || line[*i + 1] == '$'))
        //     line = backslash(line, i);
            
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	free(line);
    return (output);
}

int lexer(char *line, char **envp, t_info *info)
{
    int i;

    if (line_check(line, info))
		return (1);
    // if ((ncomands = comands_counter(line)) == -1)
		// print_error("Wrong syntax\n", info);
    i = -1;
    while(line[++i])
    {
        if (line[i] == '\'')
            line = quote(line, &i);
        if (line[i] == '\"')
            line = dquote(line, &i, envp);
        // if (line[i] == '\\')
        //     line = backslash(line, &i);
        if (line[i] == '$')
            line = envi(line, &i, envp);
        // printf("line: %s\n", line);
    }
	// envp[0] = 0;
	printf("%s\n", line);
	return (0);
}