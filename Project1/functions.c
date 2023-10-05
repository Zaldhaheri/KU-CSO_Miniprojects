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
    int s = x >> n;
    int r = ~0 << (32 + ~n) << 1;
    r = ~r;
    return (r & s);
}

unsigned int bitCount(unsigned int x)
{
    int i = 31;
    int count = 0;
    while (x)
    {
        count += (x & 1);
        x >>= 1;
    }
    return (count);
}

unsigned int Bang(unsigned int x)
{
    return ((x | (~x + 1)) >> 31) ^ 1;

}

unsigned int LeastBitPos(unsigned int x)
{
    return (x & (~x + 1));
}

unsigned int Tmax(void)
{
    return (2147483647);
}

int isNonNegative(int x)
{
    return !(x >> 31);
}

unsigned int isGreater(unsigned int x, unsigned int y)
{
    unsigned int r = (~y + x) >> 31;
    return !(r);
}

unsigned int DivPwr2(unsigned int x, unsigned char n)
{
    return x >> n;
}

int Abs(int x)
{
    if (isNonNegative(x))
        return x;
    return -x;
}

int addOk(int x, int y)
{
    int add = x + y;
    int check = ((x ^ add) & (y ^ add)) >> 31;
    return !check;
}