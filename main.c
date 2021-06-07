#include "shelly.h"

int main()
{
    char *line;

    while (1)
    {
        line = 0;
        printf("selly> ");
        get_next_line(0, &line);
        lexer(line);
    }
    
    return (0);
}
