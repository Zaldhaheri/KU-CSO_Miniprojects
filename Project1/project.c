#include "project.h"
#include <stdio.h>

void print_bits(unsigned int x)
{
    int i = 7;
    int bit;
    while (i >= 0)
    {
        bit = (x >> i) & 1;
        printf("%d", bit);
        i--;
    }
}

int main()
{
    printf("%d", Abs(-1));
    return (0);
}
