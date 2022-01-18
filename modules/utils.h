
#ifndef UTILS_H
#define UTILS_H

#define MAXLINE 1000 /* maximum input line length */

#define SAFE_SWAP(t, x, y) do {t temp; temp = x; x = y; y = temp;} while (0)

#define SWAP(x, y) do { a ^= b ^= a ^= b;} while (0)

double c_atof(char s[]);

int c_atoi(char s[]);

int c_binsearch(int x, int v[], int n);

int c_bitcount(unsigned x);

int c_getint(int *pn);

int c_getline(char s[], int lim);

int c_lower(int c);

int c_readlines(char *lineptr[], int maxlines);

int c_rand(void);

int c_strcmp(char *s, char *t);

int c_strend(char *s, char *t);

int c_strindex(char s[], char t[]);

int c_strlen(char s[]);

unsigned c_getbits(unsigned x, int p, int n);

unsigned c_invert(unsigned x, int p, int n);

unsigned c_rightrot(unsigned x, int n);

unsigned c_setbits(unsigned x, int p, int n, unsigned y);

void c_bin(unsigned x);

void c_copy(char to[], char from[]);

void c_itoa(int n, char s[]);

void c_itob(int n, char s[], int b);

void c_print_array(int v[], int len);

void c_qsort(int v[], int left, int right);

void c_reverse(char s[]);

void c_shellsort(int v[], int n);

void c_squeeze(char s[], int c);

void c_srand(unsigned int seed);

void c_strcat(char s[], char t[]);

void c_strcpy(char *s, char *t);

void c_swap(int *px, int *py);

void c_writelines(char *lineptr[], int nlines);

#endif