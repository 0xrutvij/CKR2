#include "pseudomem.h"

/* return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n; /* old p */
    }
    else 
    {
        return 0;
    }
}

/* free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
}