// cody by tim, L2Q6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define JA 1   //
#define NEIN 0 //

int main(void)
{
    unsigned int note, bestanden;                    // define variables
    printf("Geben Sie bitte eine Note (1-5) ein: "); // ask for inputs
    scanf("%u", &note);                              // wait for inputs
    switch (note)                                    // define "bestanden" if case matches "note"s value
    {
    case 1: // you could also use the predefined constants "Spitze"-"Ausreichend"
    case 2: //
    case 3: //
    case 4: //
        bestanden = JA;
        break;
    default:
        bestanden = NEIN;
        break;
    }

    bestanden                          // print "OK" or "Nicht bestanden" according to variable "bestanden"
        ? printf("\nOK!")              //
        : printf("\nNICHT bestanden"); //
    return 0;                          // no error
}
