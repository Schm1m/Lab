// cody by tim, L8Q6

#include <stdio.h>

char getFirstCapitalLetter(char[], int);  // function prototype

int main(int argc, char *argv[]) {
    char x[20];                                 // no max length was given, but 20 works for the given tests
    scanf("%s", x);                             // get input string
    printf("%c", getFirstCapitalLetter(x, 0));  // print the first capital letter or whitespace character if none is present
}

char getFirstCapitalLetter(char s[], int i) {
    if (s[i] == '\0') return ' ';                                                  // return whitespace character if no capital letter is found
    return (s[i] >= 'A' && s[i] <= 'Z') ? s[i] : getFirstCapitalLetter(s, i + 1);  // re-initiate function until a capital letter is found or the end of tring is reached
}