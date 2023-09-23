#include "project.h"
#include <stdio.h>

int main()
{
    unsigned int a = 0b10101010;
    unsigned int b = 0b11001100;
    unsigned int c = NOR(a, b);
    int i = 7;
    int bit;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        printf("%d", bit);
        i--;
    }
    return (0);
}
