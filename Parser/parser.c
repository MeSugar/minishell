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
    if (!ft_isalpha(line[0]) && line[0] != '<' && line[0] != '>' && line[0] != '\"' && line[0] != '\'')
		return (print_error("Wrong syntax\n", info));
	info->elements++;
    while (line[++i])
    {
        if (line[i] == '\'' && !quotes && !dquotes)
		{
			quotes = 1;
			info->quoted_lines++;
		}
        else if (line[i] == '\'' && quotes && !dquotes)
            quotes = 0;
        else if (line[i] == '\"' && !dquotes && !quotes)
		{
			dquotes = 1;
			info->quoted_lines++;
		}
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

char	**check_tabs(char **line)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
			if (line[i][j] == '\a')
				line[i][j] = ' ';
	}
	return (line);
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
	if (!curr_str && !envp[j])
		return (ft_strjoin(prev_str, next_str));
	output = ft_strjoin(prev_str, curr_str);
	output = ft_strjoin(output, next_str);
    return (output);
}

char *quote(char *line, int *i)
{
	int		frst_quote;
    char	*prev_str;
	char	*curr_str;
	char	*next_str;
	char	*output;

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
	*i = (*i) - 2;
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
		if (line[*i] == '$')
			line = envi(line, i, envp);
		// if (line[*i] == ' ')
		// 	line[*i] = '\a';
        if (line[*i] == '\"')
		{
			curr_str = malloc(sizeof(char) * ((*i) - frst_quote));
    		curr_str = ft_memcpy(curr_str, line + frst_quote + 1, (size_t)((*i) - frst_quote - 1));
			break;
		}
        // if (line[*i] == '\\' && (line[*i + 1] == '\"' || line[*i + 1] == '\\' || line[*i + 1] == '$'))
        //     line = backslash(line, i);
            
    }
	output = ft_strjoin(prev_str, curr_str);
	next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(output, next_str);
	// printf("char is %c\n", output[5]);
	*i = (*i) - 1;
	free(line);
    return (output);
}

int	check_last_arg(char **output, char **envp, t_info *info)
{
	int i;

	i = -1;
	if (!(*output))
		return (0);
	while ((*output)[++i])
	{
		if ((*output)[i] == '|' || (*output)[i] == '<' || (*output)[i] == '>')
		{
			// *prev_str = malloc(sizeof(char) * (i + 1));
			// if (!prev_str)
			// {
			// 	print_error(strerror(errno), info);
			// 	return (-1);
			// }
    		// *prev_str = ft_memcpy(*prev_str, *output, (size_t)(i));
			// *output = ft_strdup((*output) + i + 1);
			// info->tail->lines++;
			// return (1);
			break ;
		}
		if ((*output)[i] == '\'')
			*output = quote(*output, &i);
		if ((*output)[i] == '\"')
			*output = dquote(*output, &i, envp);
		if ((*output)[i] == '$')
			*output = envi(*output, &i, envp);
		// printf("number %d\n", i);
		// printf("char is %c\n", (*output)[4]);
		// printf("char is %c\n", (*output)[5]);
		// printf("char is %c\n", (*output)[6]);
		// printf("str is %s\n", (*output));
		if ((*output)[i] == ' ' || (*output)[i] == '\t')
			return (0);
	}
	info->tail->lines++;
	return (1);
}

char *space(char *line, int *i, t_info *info, char **envp)
{
	char *output;
	char *prev_str;

	// printf("before removing space: %s\n", line);
	prev_str = malloc(sizeof(char) * (*i + 1));
	if (!prev_str)
	{
		print_error(strerror(errno), info);
		return (0);
	}
	if (line[(*i) - 1])
    	prev_str = ft_memcpy(prev_str, line, (size_t)(*i));
	// printf("to add: %s\n", prev_str);
	if (!info->tail)
		add_element(init_element(info), info);
	info->tail->lines++;
	// printf("afte init: hello\n");
	info->tail->command = add_line_to_arr(prev_str, info->tail, info);
	ft_skip_whitespaces(i, line);
	// printf("after skipping space: %s\n", line + (*i));
	output = ft_strdup(line + *i);
	*i = -1;
    printf("out: %s\n", output);
	if (check_last_arg(&output, envp, info))
	{
		info->tail->command = add_line_to_arr(output, info->tail, info);
	}
	//
	int j;
	t_command_list *tmp = info->head;
	while (tmp)
	{
		j = 0;
		while (tmp->command[j])
		{
			printf("%s\n", tmp->command[j]);
			j++;
		}
		tmp = tmp->next;
	}
	if (!output)
		return (0);
	return (output);
}

int parser(char *line, char **envp, t_info *info)
{
    int i;
    // char **arr;

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
		if (line[i] == ' ' || line[i] == '\t')
			line = space(line, &i, info, envp);
		// if 
        // printf("line: %s\n", line);
    }
	// if (ft_strchr(line, '|'))
	// 	arr = split_by_pipe(line);
    printf("line: %s\n", line);
	// new_line = ft_split_modified(line);
	// new_line = check_tabs(new_line);
	// envp[0] = 0;
	//
	// int j = -1;
	// while (new_line[++j])
	// 	printf("%s\n", new_line[j]);
	//
	return (0);
}