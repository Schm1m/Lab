// cody by tim, L8Q5

#include <stdio.h>

float row(float, float, int);  // function prototype

int main(int argc, char *argv[]) {
    float v1, v2;                      // initiate floats
    int v3;                            // initiate ints
    scanf("%f %f %d", &v1, &v2, &v3);  // get inputs
    printf("%0.1f", row(v1, v2, v3));  // return row calculations
}

float row(float a, float x, int n) {
    return n == 0 ? 0 : a + ((2 * n) * x) + row(a, x, n - 1);
}