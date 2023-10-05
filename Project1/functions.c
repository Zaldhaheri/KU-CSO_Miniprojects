#include "project.h"

unsigned int NOR(unsigned int x, unsigned int y)
{
    return ((~x) & (~y));
}

unsigned int XOR(unsigned int x, unsigned int y)
{
    return (x & ~y) + (~x & y);
}

unsigned int isNotEqual(unsigned int x, unsigned int y)
{
    return !!(x ^ y);
}

unsigned char getByte(unsigned int x, unsigned char n)
{
    return (0b1111 & (x >> (n << 2)));
}

unsigned int copyLSB(unsigned int x)
{
    unsigned int LSB = 1 & x;
    LSB |= (LSB << 16);
    LSB |= (LSB << 8);
    LSB |= (LSB << 4);
    LSB |= (LSB << 2);
    LSB |= (LSB << 1);
    return LSB;
}

unsigned int logicalShift(unsigned int x, unsigned char n)
{
    return (x >> n);
}

unsigned int bitCount(unsigned int x)
{
    int i = 31;
    int count = 0;
    while (i >= 0)
    {
        if ((x >> i) & 1 == 1)
            count++;
        i--;
    }
    return (count);
}

unsigned int Bang(unsigned int x)
{
    return (~x & 1);
}

unsigned int LeastBitPos(unsigned int x)
{
    unsigned int i;
    if (!x)
    {
        return (0);
    }
    for(i = 0; i < 32; i++)
    {
        if ((1 << i) & x)
        {
            return ((1 << i) & x);
        }
    }
}

unsigned int Tmax(void)
{
    return (2147483647);
}

unsigned int isNonNegative(unsigned int x)
{

}

// unsigned int isGreater(unsigned int x, unsigned int y)
// {

// }

unsigned int DivPwr2(unsigned int x, unsigned char n) //fix no /
{
    return x / (1 << n);
}

int Abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}

// unsigned int addOk(unsigned int x, unsigned int y)
// {

// }