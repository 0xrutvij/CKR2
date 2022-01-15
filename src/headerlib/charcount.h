#include <stdio.h>

#ifndef CHARCOUNT_H
#define CHARCOUNT_H

/* Count characters in input; 1st version */
void char_count1()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}

void char_count2()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

#endif