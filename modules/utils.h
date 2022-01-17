
#ifndef UTILS_H
#define UTILS_H

#define MAXLINE 1000 /* maximum input line length */

int c_atoi(char s[]);

int c_bitcount(unsigned x);

int c_getline(char s[], int lim);

int c_lower(int c);

int c_rand(void);

int c_strlen(char s[]);

void c_bin(unsigned x);

void c_copy(char to[], char from[]);

void c_squeeze(char s[], int c);

void c_srand(unsigned int seed);

void c_strcat(char s[], char t[]);

unsigned c_getbits(unsigned x, int p, int n);

unsigned c_invert(unsigned x, int p, int n);

unsigned c_rightrot(unsigned x, int n);

unsigned c_setbits(unsigned x, int p, int n, unsigned y);

#endif