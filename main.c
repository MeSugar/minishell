#include "shelly.h"

int main()
{
    char *line;

    while (1)
    {
        t_lex *lex;
        line = 0;
        printf("selly$ ");
        get_next_line(0, &line);
        lexer(line, lex);
    }
    
    return (0);
}
