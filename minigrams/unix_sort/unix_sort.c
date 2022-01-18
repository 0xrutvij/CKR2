#include <stdio.h>
#include <string.h>
#include "../../modules/utils.h"

#define MAXLINES 5000       /* max #lines to be sorted */

char *lineptr[MAXLINES];   /* pointers to text lines */

void qsort(char *lineprtr[], int left, int right);

/* sort input lines */
int main(int argc, char const *argv[])
{
    int nlines; /* number of input lines read */

    if ((nlines = c_readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        c_writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort \n");
        return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void char_swap(char *v[], int i, int j);

    if (left >= right)
        return;

    char_swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            char_swap(v, ++last, i);

    char_swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* char_swap: interchange chars at v[i] and v[j] */
void char_swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}