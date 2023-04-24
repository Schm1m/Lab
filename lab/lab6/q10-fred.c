#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int prime(unsigned int input) {

    if (input <= 1) {

        return 0;

    }

    unsigned int i = 2;

    while (i * i <= input) {

        if (input % i == 0) {

            return 0;

        }

        i++;

    }

    return 1;

}

int main(void) {

    printf(prime(85) ? "Primzahl" : "KEINE Primzahl");

}