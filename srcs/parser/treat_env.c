#include "parser.h"

static void	save_prev_key_next_lines(t_ft_env *env, char *line, int *i)
{
	env->prev_str = malloc(sizeof(char) * (*i + 1));
	env->prev_str = ft_memcpy(env->prev_str, line, (size_t)(*i));
	while (line[++(*i)])
	{
		if ((line[*i + 1] != '_' && !ft_isalnum(line[*i + 1]))
			|| (line[*i] != '_' && !ft_isalnum(line[*i])))
		{
			env->key = malloc(sizeof(char) * ((*i) - env->start + 1));
			env->key = ft_memcpy(env->key, line + env->start + 1,
					(size_t)((*i) - env->start));
			break ;
		}
	}
	env->next_str = strdup(line + *i + 1);
}

static void	save_curr_line(t_ft_env *env, char **envp, t_info *info)
{
	while (envp[++env->j])
	{
		if (!ft_strncmp(env->key, envp[env->j], ft_strlen(env->key))
			&& envp[env->j][ft_strlen(env->key)] == '=')
		{
			env->curr_str = malloc(sizeof(char)
					* (ft_strlen(envp[env->j]) - ft_strlen(env->key)) + 1);
			env->curr_str = ft_memcpy(env->curr_str, envp[env->j]
					+ ft_strlen(env->key) + 1,
					ft_strlen(envp[env->j]) - ft_strlen(env->key));
			break ;
		}
	}
	if (env->key[0] == '?' && !env->key[1] && !env->curr_str)
		env->curr_str = ft_itoa(info->status);
}

static char	*delete_env_sign(t_ft_env *env, char *line, int *i)
{
	char	*output;

	output = 0;
	env->prev_str = malloc(sizeof(char) * (*i + 1));
	env->prev_str = ft_memcpy(env->prev_str, line, (size_t)(*i));
	env->next_str = ft_strdup(line + *i + 1);
	output = ft_strjoin(env->prev_str, env->next_str);
	free_env(env, line);
	(*i)--;
	return (output);
}

static char	*save_env_output(t_ft_env *env, int *i, char *line)
{
	char	*output;

	output = 0;
	env->tmp = ft_strjoin(env->prev_str, env->curr_str);
	output = ft_strjoin(env->tmp, env->next_str);
	if (env->curr_str)
		*i = ft_strlen(env->curr_str) - 1 + env->start;
	free_env(env, line);
	return (output);
}

char	*treat_env(char *line, int *i, char **envp, t_info *info)
{
	t_ft_env	*env;
	char		*output;

	env = init_env(info, i);
	if (((line[*i + 1] == '\'' || line[*i + 1] == '\"') && !in_quotes(line, i)))
		return (delete_env_sign(env, line, i));
	if (line[env->start + 1] != '_' && line[env->start + 1] != '?'
		&& !ft_isalnum(line[env->start + 1]))
	{
		free(env);
		return (line);
	}
	save_prev_key_next_lines(env, line, i);
	save_curr_line(env, envp, info);
	if (!env->curr_str && !envp[env->j])
	{
		output = ft_strjoin(env->prev_str, env->next_str);
		free_env(env, line);
		*i = env->start;
		if (output && (output[*i] == '$' || output[*i] == '\"'))
			(*i)--;
		return (output);
	}
	output = save_env_output(env, i, line);
	return (output);
}
