#include <stdio.h>

int get_sign(float x)
{
    if (x >= 0)
        return 0;
    return 1; //return sign bit 1 negative, 0 positive
}

int get_exp(float x)
{
    int exp;
    int *ptr = (int *)&x; //reinterpret x as an int
    return (*ptr >> 23) & 0xFF; //returns the shifts over the mantissa and masks exponent bits
}

float get_man(float x);

int main()
{
    float x;
    float y;
    printf("Enter float x: ");
    scanf(" %f", &x);
    printf("Enter float y: ");
    scanf(" %f", &y);
    int signx = get_sign(x);
    int signy = get_sign(y);
    int expx = get_exp(x);
    int expy = get_exp(y);
}