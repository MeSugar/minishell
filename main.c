#include "shelly.h"

t_info	*init_struct(void)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if (!info)
		print_error("Malloc error\n", 0);
	info->head = 0;
	info->tail = 0;
	info->elements = 0;
	info->quoted_lines = 0;
	info->quoted = 0;
	info->added_quoted_lines = -1;
	return (info);
}


int main(int ac, char **av, char **envp)
{
	t_info *info;
    char *line;

	// info = init_struct();
    if (ac == 0)
		return (0);
    while (1)
    {
		info = init_struct();
        line = 0;
        // printf("selly> ");
        // get_next_line(0, &line);
        line = readline("selly> ");
        parser(line, envp, info);
    }
    (void)av;
    
    return (0);
}
