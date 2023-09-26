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
    if(x ^ y)
        return (1);
    return (0);
}

// unsigned char getByte(unsigned int x, unsigned char n)
// {
//     //idk
// }

// unsigned int copyLSB(unsigned int x)
// {
//     //idk
// }

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

// unsigned int Bang(unsigned int x)
// {

// }

// unsigned int LeastBitPos(unsigned int x)
// {

// }

// unsigned int Tmax(void)
// {

// }

// unsigned int isNonNegative(unsigned int x)
// {

// }

// unsigned int isGreater(unsigned int x, unsigned int y)
// {

// }

// unsigned int DivPwr2(unsigned int x, unsigned char n)
// {

// }

unsigned int Abs(unsigned int x)
{
    unsigned int signBit = x >> 31;
    return (x + signBit) ^ signBit;
}

// unsigned int addOk(unsigned int x, unsigned int y)
// {

// }