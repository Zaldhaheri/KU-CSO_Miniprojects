#include <stdio.h>
#include "project.h"

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

void print_byte(unsigned int x)
{
    int i = 3;
    int bit;
    while (i >= 0)
    {
        bit = (x >> i) & 1;
        printf("%d", bit);
        i--;
    }
}

int print_funcs(void)
{
    int d;
    unsigned int x;
    unsigned int y;
    unsigned char n;
    printf("\nWhich function would you like to enter: 1 to 15\n1. NOR(x,y)\n2. XOR(x,y)\n");
    printf("3. isNotEqual(x,y)\n4. getByte(x,n)\n5. copyLSB(x)\n6. logicalShift(x,n)\n");
    printf("7. bitCount(x)\n8. Bang(x)\n9. leastBitPos(x)\n10. Tmax(void)\n11. isNonNegative(x)\n");
    printf("12. isGreater(x,y)\n13. Divpwr2(x,n)\n14. Abs(x)\n15. addOk(x,y)\n0. Exit\n");
    printf("Function: ");
    scanf("%d", &d);
    if (d > 0 && d <= 15)
    {
        if (d == 1)
        {
            printf("x = ");
            scanf("%u", &x);
            printf("y = ");
            scanf("%u", &y);
            print_bits(NOR(x,y));
        }
        else if (d == 2)
        {
            printf("x = ");
            scanf("%u", &x);
            printf("y = ");
            scanf("%u", &y);
            print_bits(XOR(x,y));
        }
        else if (d == 3)
        {
            printf("x = ");
            scanf("%u", &x);
            printf("y = ");
            scanf("%u", &y);
            printf("%u", isNotEqual(x, y));
        }
        else if (d == 4)
        {
            printf("x = ");
            scanf(" %u", &x);
            printf("n = ");
            scanf(" %hhu", &n);
            print_byte(getByte(x, n));
        }
        else if (d == 5)
        {
            printf("x = ");
            scanf(" %u", &x);
            print_bits(copyLSB(x));
        }
        else if (d == 6)
        {
            printf("x = ");
            scanf("%u", &x);
            printf("n = ");
            scanf("%hhu", &n);
            print_bits(logicalShift(x,n));
        }
        else if (d == 7)
        {
            printf("x = ");
            scanf(" %u", &x);
            printf("%u", bitCount(x));
        }
        else if (d == 8)
        {
            printf("x = ");
            scanf(" %u", &x);
            printf("%u", Bang(x));
        }
        else if (d == 9)
        {
            printf("x = ");
            scanf(" %u", &x);
            print_bits(LeastBitPos(x));
        }
        else if (d == 10)
        {
            printf("%u", Tmax());
        }
        else if (d == 11)
        {

        }
        else if (d == 12)
        {

        }
        else if (d == 13)
        {

        }
        else if (d == 14)
        {
            printf("x = ");
            scanf("%u", &x);
            printf("%d", Abs(x));
        }
        else if (d == 15)
        {

        }
        return (1);
    }
    else if (d == 0)
    {
        printf("Goodbye\n");
        return (0);
    }
    else
    {
        printf("Function out of bounds\n");
        return (1);
    }
}

int main()
{
    int d = 1;
    while(d)
    {
        d = print_funcs();
    }
}
