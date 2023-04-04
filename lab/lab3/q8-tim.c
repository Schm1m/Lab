// cody by tim, L3Q8

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int note = 0;

    while (note < 1 || note > 5)
    {
        printf("\nGeben Sie bitte eine Note (1-5) ein: "); // ask for input
        scanf("%d", &note);                                // wait for input
    }
    switch (note)                    // if note is one of:
    {                                //
    case 1:                          // 1
    case 2:                          // 2
    case 3:                          // 3
    case 4:                          // 4
        printf("\nOK!");             // print "OK!"
        break;                       //
    default:                         // else:
        printf("\nNICHT bestanden"); // print "NICHT bestanden"
        break;
    }

    return 0;
}