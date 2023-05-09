// cody by tim, L8Q7

#include <stdio.h>

int isPrime(int, int);  // function prototype

int main(int argc, char *argv[]) {
    int x;                        // initiate var
    scanf("%d", &x);              // get input
    printf("%d", isPrime(x, 2));  // print if is prime (1) or not (0)
}

int isPrime(int a, int i) {
    if (a <= 2 && a > 0) return a - 1;  // exclude 1 and 2 as the dont work with this "algorythm"
    if (a % i == 0) {                   // check if a is divideable by the current i
        return 0;                       // if so return no prime (0)
    }
    return (i * i > a) ? 1 : isPrime(a, i + 1);  // if no matching i is found return is prime (1)
}