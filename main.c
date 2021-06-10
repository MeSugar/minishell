#include "shelly.h"

int main(int ac, char **av, char **envp)
{
    char *line;
    if (ac == 0)
		return (0);
    while (1)
    {
        line = 0;
        // printf("selly> ");
        // get_next_line(0, &line);
        line = readline("selly> ");
        lexer(line, envp);
    }
    (void)av;
    
    return (0);
}
