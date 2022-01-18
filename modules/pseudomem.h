
#ifndef PSEUDOMEM_H
#define PSEUDOMEM_H

#define ALLOCSIZE 10000   /* size of available space */
char allocbuf[ALLOCSIZE]; /* storage for alloc */
char *allocp = allocbuf;  /* next free position */

char *alloc(int n);

void afree(char *p);

#endif