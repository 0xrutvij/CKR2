#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "buffer.h"
#include "utils.h"
#include "pseudomem.h"

unsigned long int next = 1;
#define dprint(expr) printf(#expr " = "); c_bin(expr); printf("\n")

#define ALL_ONES (unsigned) ~0

/* c_getline: read a line into s, return length */
int c_getline(char s[], int lim)
{
    int c, i = 0;

    while (--lim > 0 && (c=getchar()) != EOF && c!= '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* c_copy: copy 'from' into 'to'; assume to is big enough */
void c_copy(char to[], char from[]) {

    for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}

/* c_atoi: convert s to integer */
int c_atoi(char s[]) {

    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;

    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}

/* c_lower: convert c to lower case; ASCII only */
int c_lower(int c) {
    
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

/* c_strlen: return length of s */
int c_strlen(char s[]){

    int n;

    for (n = 0; *s != '\0'; s++)
        n++;

    return n;
}

/* c_rand: return pseudo-random integer on 0..32767 */
int c_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* c_srand: set seed for rand() */
void c_srand(unsigned int seed) {
    next = seed;
}

/* c_squeeze: delete all c from s */
void c_squeeze(char s[], int c) {

    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }

    s[j] = '\0';
}

/* c_strcat: concatenate t to end of s; s must be big enough */
void c_strcat(char *s, char *t) {
    while (*s++)
        ;

    --s;
    while ((*s++ = *t++))
        ;
}

/* c_bin: print binary representation of a number */
void c_bin(unsigned n)
{
    if (n > 1)
        c_bin(n >> 1);

    printf("%d", n & 1);
}

/* moveToRight: Move the n bits starting at p to the right end of word */
unsigned moveToRight(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n));
}

/* zeroesInLowerN: All ones and the lower n bits are zero */
unsigned zeroesInLowerN(int n)
{
    return ALL_ONES << n;
}

/* onesInLowerN: All zeroes and the lower n bits are one */
unsigned onesInLowerN(int n)
{
    return ~zeroesInLowerN(n);
}

/* c_getbits: get n bits from position p, where position 0 is at the right end */
unsigned c_getbits(unsigned x, int p, int n)
{
    unsigned mask = onesInLowerN(n);
    unsigned desired_field = moveToRight(x, p, n);
    
    return desired_field & mask;
}

/* c_setbits: returns x w/ n bits that begin @p set to rightmost n bits of y */
unsigned c_setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned new_n = y & onesInLowerN(n);
    unsigned shift = (p + 1 - n);
    unsigned mask = ~(onesInLowerN(n) << shift);
    unsigned n_bits_unset = x & mask;

    return n_bits_unset | (new_n << shift);
}

/* c_invert: return x with the n bits that begin at p inverted */
unsigned c_invert(unsigned x, int p, int n)
{
    unsigned bits_to_flip = c_getbits(x, p, n);
    unsigned flipped_bits = ~bits_to_flip;
    unsigned return_value = c_setbits(x, p, n, flipped_bits);

    return return_value;
}

/* c_rightrot: returns value of int x rotated to the right by n */
unsigned c_rightrot(unsigned x, int n)
{
    unsigned bits = sizeof(unsigned) * 8;

    if (n == 0 || n%bits == 0)
    {
        return x;
    }

    unsigned shifted_to_right = x >> n;
    unsigned overflow = x << (bits - n);

    return overflow | shifted_to_right;
}

/* c_bitcount: count 1 bits in x */
int c_bitcount(unsigned x)
{
    int count = x ? 1 : 0;

    while (x &= (x-1))
        ++count;

    return count;
}

/* c_binsearch: find x in v[0] <= v[1] <= v[n-1] */
int c_binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/* c_print_array: Prints the contents of an array */
void c_print_array(int v[], int len)
{
    printf("\n[");
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
    }
    printf("]");
}

/* c_shellsort: sort v[0]...v[n-1] into increasing order */
void c_shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j-= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

/* c_reverse: reverse a string s in place */
void c_reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}


/* c_itoa: convert n to characters in s */
void c_itoa(int n, char s[])
{
    int i, sign, adjust;
    adjust = 0;

    if (n == INT_MIN)               /* if int is equal to lower limit */
    {
        n = n + 1;                  /* make it one more than lower limit to allow for negation*/
        adjust = 1;                 /* in the end correct for the change by adding adjust */
    }

    if ((sign = n) < 0)             /* record sign */
        n = -n;                     /* make n positive */

    i = 0;
    do {                            /* generate digits in reverse order */
        s[i++] = n % 10 + '0';      /* get next digit */
    } while ((n /= 10) > 0);        /* delete it */

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    c_reverse(s);
    if (adjust)
    {
        s[i - 1] += 1;
    }
}

/* c_itob: integer n into a base b char representation in the string s. b is one of 2, 8, 16 */
void c_itob(int n, char s[], int b)
{
    int i = 0, val;
    switch (b)
    {
    case 16:
        for (i = 0; n != 0; n>>=4, i++)
        {
            val = n & 0xf;
            s[i] = (val < 10) ? val + '0' : (val - 10) + 'a';
        }
        break;

    case 8:
        for (i = 0; n != 0; n>>=3, i++)
        {
            val = n & 0x7;
            s[i] = (val % 8) + '0';
        }
        break;

    case 2:
        for (i = 0; n != 0; n>>=1, i++)
        {
            val = n & 0x1;
            s[i] = (val % 2) + '0';
        }
        break;

    default:
        printf("\nerror invalid base value, use one of 2, 8, 16.\n");
        break;
    }
    s[i] = '\0';
    c_reverse(s);
}

/* c_strindex: return index of t in s, -1 if none */
int c_strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* c_atof: convert string s to double */
double atof(char s[])
{
    double val, power, exp_power;
    int i, sign, exp_sign;

    for (i = 0; isspace(s[i]); i++)    /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.9 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exp_power = 0; isdigit(s[i]); i++)
    {
        exp_power *= 10;
        exp_power += (s[i] - '0');
    }

    return (sign * val / power) * pow(10, exp_sign * exp_power);
}

/* c_swap: swap the variables in px & py */
void c_swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

/* swap_array: interchange v[i] and v[j] */
void static swap_array(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* c_qsort: sort v[left]...v[right] into increasing order */
void c_qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right) /* do nothing if < 2 elements */
        return;

    swap_array(v, left, (left + right) / 2);    /* move partition element */
    last = left;                                /* to v[0] */

    for (i = left + 1; i <= right; i++)         /* partition */
    {
        if (v[i] < v[left])
            swap_array(v, ++last, i);
    }
    swap_array(v, left, last);                  /* restore partition elem */
    c_qsort(v, left, last - 1);
    c_qsort(v, last + 1, right);
}

/* 
c_getint: get next integer from input int *pn.
Returns EOF for end of file, 
zero if next input is not a number 
and +ve value for valid numbers.
 */
int c_getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

/* c_strcpy: copy t to s; array subscript version */
void c_strcpy(char *s, char *t)
{
    while((*s++ = *t++))
        ;
}

/* c_strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int c_strcmp(char *s, char* t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

/* c_strend: returns 1 if the string t occurs at the end of string s, else 0 */
int c_strend(char *s, char *t)
{
    s += strlen(s) - strlen(t);

    while (*s && *s++ == *t++)
        ;

    return !*s;
}

/* c_readlines: read input lines */
int c_readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = c_getline(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* c_writelines: write output lines */
void c_writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}