#include <stdio.h>
#include <math.h>

int main()
{
    float array_nums[10];
    float Array[10];
    int i = 0;
    while (i < 10)
    {
        printf("Enter num %d: ", i + 1);
        scanf(" %f", &array_nums[i]);
        i++;
    }
    i = 0;
    while (i < 10)
    {
        printf("array_nums[%d] = %.2f\n", i, array_nums[i]);
        i++;
    }
    i = 2;
    Array[0] = array_nums[0];
    Array[1] = array_nums[1];
    printf("Array[0] = %.2f\n", Array[0]);
    printf("Array[1] = %.2f\n", Array[1]);
    while (i < 10)
    {
        Array[i] = sqrt(array_nums[i-2]*array_nums[i-2] + array_nums[i-1]*array_nums[i-1]);
        printf("Array[%d] = %.2f\n", i, Array[i]);
        i++;
    }
}