#include "shelly.h"

t_command_list	*init_element(t_info *info)
{
	t_command_list *element;

	element = malloc(sizeof(t_command_list));
	if (!element)
		print_error(strerror(errno), info);
	element->type = 0;
	element->command = 0;
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