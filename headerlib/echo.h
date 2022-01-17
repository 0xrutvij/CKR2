#include <stdio.h>

#ifndef ECHO_H
#define ECHO_H

/* copy input to output; 1st version */
void echo1()
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}

/* copy input to output; 2nd version */
void echo2()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

#endif