#include "modules/utils.h"
#include <stdio.h>
#include <limits.h>

#define print_bin(num) c_bin(num); printf("\n");

/* Print the longest input line */
int main(int argc, char const *argv[])
{
    char int_str[100];

    int z = 255;
    printf("%x\n", z);

    c_itob(z, int_str, 16);
    printf("%s\n", int_str);

    return 0;
}