#include "modules/utils.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define print_bin(num) c_bin(num); printf("\n");

/* Print the longest input line */
int main(int argc, char const *argv[])
{
    char string1[100] = "Hello, ";
    char string2[] = "World!";

    c_strcat(string1, string2);
    printf("%s\n", string1);

    return 0;
}