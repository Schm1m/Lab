#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char * append(char buffer[], const char *string) {

    char *start = buffer;
    while (*start != '\0') {

        start++;

    }

    while (*string != '\0') {

        *start++ = *string++;

    }

    *start = '\0';

    return buffer;

}

int main(void) {

    char buffer[40] = "Hallo ";
    append(buffer, "Welt");
    printf("%s\n", buffer);

}


