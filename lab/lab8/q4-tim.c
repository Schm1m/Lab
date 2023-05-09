// cody by tim, L8Q4

#include <stdio.h>

float row(float, float, int);  // function prototype

int main(int argc, char *argv[]) {
    float v1, v2;                      // initiate floats
    int v3;                            // initiate ints
    scanf("%f %f %d", &v1, &v2, &v3);  // get inputs
    printf("%0.1f", row(v1, v2, v3));  // return row calculations
}

float row(float a, float x, int n) {
    float r;
    for (int i = 1; i <= n; i++) {
        r += (a + ((2.0 * i) * x));  // for each iteration add the next row-tile to r
    }
    return r;  // return r after all tiles were added up
}