#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>

//functions go here
unsigned int NOR(unsigned int x, unsigned int y);
unsigned int XOR(unsigned int x, unsigned int y);
unsigned int isNotEqual(unsigned int x, unsigned int y);
unsigned char getByte(unsigned int x, unsigned char n);
unsigned int copyLSB(unsigned int x);
unsigned int logicalShift(unsigned int x, unsigned char n);
unsigned int bitCount(unsigned int x);
unsigned int Bang(unsigned int x);
unsigned int LeastBitPos(unsigned int x);
unsigned int Tmax(void);
int isNonNegative(int x);
unsigned int isGreater(unsigned int x, unsigned int y);
unsigned int DivPwr2(unsigned int x, unsigned char n);
int Abs(int x);
int addOk(int x, int y);

#endif