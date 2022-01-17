#include <stdio.h>
#include "utils.h"

unsigned long int next = 1;
#define dprint(expr) printf(#expr " = "); c_bin(expr); printf("\n")

#define ALL_ONES (unsigned) ~0

/* c_getline: read a line into s, return length */
int c_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
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

    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
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

    int i;

    while (s[i] != '\0')
        ++i;

    return i;
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
void c_strcat(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i)
        ;

    while ((s[i++] = t[j++]) != '\0')
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
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }

    return b;
}