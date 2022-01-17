
#ifndef UTILS_H
#define UTILS_H

#define MAXLINE 1000 /* maximum input line length */

int c_atoi(char s[]);

int c_binsearch(int x, int v[], int n);

int c_bitcount(unsigned x);

int c_getline(char s[], int lim);

int c_lower(int c);

int c_rand(void);

int c_strindex(char s[], char t[]);

int c_strlen(char s[]);

void c_bin(unsigned x);

void c_copy(char to[], char from[]);

void c_itoa(int n, char s[]);

void c_itob(int n, char s[], int b);

void c_print_array(int v[], int len);

void c_shellsort(int v[], int n);

void c_squeeze(char s[], int c);

void c_srand(unsigned int seed);

void c_strcat(char s[], char t[]);

void c_reverse(char s[]);

unsigned c_getbits(unsigned x, int p, int n);

unsigned c_invert(unsigned x, int p, int n);

unsigned c_rightrot(unsigned x, int n);

unsigned c_setbits(unsigned x, int p, int n, unsigned y);

#endif