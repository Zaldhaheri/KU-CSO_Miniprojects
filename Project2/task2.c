#include <stdio.h>
#include <math.h>

int main() {
    float x, y;
    printf("Enter two decimal values (x and y): ");
    if (scanf("%f %f", &x, &y) != 2) {
        printf("Invalid input. Please enter valid float numbers.\n");
        return 1;
    }

    int sign_x = 1, sign_y = 1;
    if (x < 0) {
        sign_x = -1;
        x = -x;
    }
    if (y < 0) {
        sign_y = -1;
        y = -y;
    }

    int exp_x, exp_y;
    float mantissa_x, mantissa_y;
    mantissa_x = frexpf(x, &exp_x);
    mantissa_y = frexpf(y, &exp_y);

    // Multiply the mantissas
    float mantissa_result = mantissa_x * mantissa_y;

    // Add the exponents
    int exp_result = exp_x + exp_y;

    // Check the sign of the result
    int sign_result = sign_x * sign_y;

    // Calculate the result
    float result = ldexpf(mantissa_result, exp_result) * sign_result;

    // Round the result
    float rounded_result = roundf(result);
    printf("rounded result: %.5f\n", rounded_result);
    printf("result = %.5f\n", result);
    printf("x * y = %.5f\n", x * y);

    // Check if Z equals x * y
    int Z = ((int) result == (int) (x * y)) ? 1 : 0;

    printf("Z = %d\n", Z);

    return 0;
}
