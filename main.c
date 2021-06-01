#include "shelly.h"

int main()
{
    char *line;
    int ret;

    line = 0;

    ret = get_next_line(0, &line);
    if (ret)
        printf("%s\n", line);
    return (0);
}
