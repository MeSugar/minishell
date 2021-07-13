#include "shelly.h"

t_command_list	*init_element(t_info *info)
{
	t_command_list *element;

	element = malloc(sizeof(t_command_list));
	if (!element)
	{
		print_error(strerror(errno), info);
		return (0);
	}
	element->type = 0;
	element->command = 0;
	element->lines = 0;
	element->redirect = 0;
	element->file_name = 0;
	element->next = 0;
	return (element);
}

void	add_element(t_command_list *element, t_info *info)
{
	if (!info->head)
	{
		info->head = element;
		info->tail = element;
	}
	else
	{
		info->tail->next = element;
		info->tail = element;
	}
}

char **add_line_to_arr(char *line, t_command_list *command, t_info *info)
{
	char	**arr;
	// int		i;

	arr = malloc(sizeof(char *) * (command->lines + 1));
	if (!arr)
	{
		print_error(strerror(errno), info);
		return (0);
	}
	int j;
	j = -1;
	if (command->command)
	{
		printf("---\n");
		while (command->command[++j])
		{
			printf("%s\n", command->command[j]);
		}
		printf("---\n");
	}
	if (command->command)
	{
		int z = -1;
		while (command->command[++z])
			printf("zzz %s\n", command->command[z]);
		arr = command->command;
	}
	arr[command->lines - 1] = line;
	if (info->head->lines == 4)
	{	
		printf("arr %s\n", arr[0]);
		printf("arr %s\n", arr[1]);
		printf("arr %s\n", arr[2]);
	}
	printf("arr %s\n", arr[command->lines - 1]);
	printf("last line %d\n", command->lines);
	arr[command->lines] = 0;
	if (command->lines == 4)
	{
		while(*arr)
		{

			printf("arsa %s\n", *arr);
			arr++;
		}
	}
	// i = -1;
	// if (command->command)
	// {
	// 	while (command->command[++i])
	// 		free(command->command[i]);
	// 	free(command->command);
	// }
	int f = -1;
	while (arr[++f])
		printf("sss %s\n", arr[f]);
	return (arr);
}