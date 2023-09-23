#include "project.h"

unsigned int XOR(unsigned int x, unsigned int y)
{
    return (x & ~y)+(~x & y);
}