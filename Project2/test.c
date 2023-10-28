#include <stdio.h>

void print_bits(unsigned int x)
{
    int i = 31;
    int bit;
    while (i >= 0)
    {
        bit = (x >> i) & 1;
        printf("%d", bit);
        i--;
    }
}

int productSign(float x, float y)
{
    if ((x < 0 && y > 0) || (x > 0 && y < 0))
        return 1;
    else
        return 0;
}

int getSumExponent(float x, float y)
{
    unsigned int *ptr1 = (unsigned int*) &x;
    unsigned int *ptr2 = (unsigned int*) &y;
    int exp1 = *ptr1 & 0x7f800000;
    int exp2 = *ptr2 & 0x7f800000;
    exp1 >>= 23;
    exp2 >>= 23;
    return (exp1 + exp2);
}

int multiplyMantissa(float x, float y)
{
    unsigned int *ptr1 = (unsigned int*) &x;
    unsigned int *ptr2 = (unsigned int*) &y;
    int man1 = *ptr1 & 0x007fffff;
    int man2 = *ptr2 & 0x007fffff;
    return (man1 * man2);
}

int main()
{
    float x, y;
    printf("Enter two floating type x and y: ");
    scanf(" %f %f", &x, &y);
    printf("Sign bit of the product: %d\n", productSign(x, y));
    printf("Sum of exponents: %d\n", getSumExponent(x, y));
    printf("Product of Mantissa: %d\n", multiplyMantissa(x, y));
    float z;
}