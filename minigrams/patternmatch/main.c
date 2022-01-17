#include <stdio.h>
#include "../../modules/utils.h"

char pattern[] = "ould";                /* pattern to search for */

/* find all lines matching pattern */
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;

    while (c_getline(line, MAXLINE) > 0)
    {
        if (c_strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }
    return 0;
}
