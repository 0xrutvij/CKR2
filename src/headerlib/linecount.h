#include <stdio.h>

#ifndef LINECOUNT_H
#define LINECOUNT_H

/* count lines in input */
void countlines()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}

#endif