#include "project.h"

unsigned int NOR(unsigned int x, unsigned int y)
{
    return ((~x) & (~y));
}