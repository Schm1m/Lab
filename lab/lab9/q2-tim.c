// cody by tim, L9Q2

#include <stdio.h>
// #include <string.h>
// we dont need string.h even if its given in the input field on reset

struct person {  // define struct for peronal data
    int id;
    char* surname;
    char* lastname;
};

typedef struct person user;  // define type for the struct

void printUser(user);  // function prototype

int main(void) {
    char sur[20], last[20];  // initiate vars for input
    int num;
    user one = {1, "Hans", "Maurer"};    // define pre-defined person 1
    scanf("%d %s %s", &num, sur, last);  // get data for person 2
    user two = {num, sur, last};         // define person 2
    printUser(one);                      // print person
    printUser(two);                      // ""

    return 0;
}

void printUser(user x) {
    printf("%d: %s %s\n", x.id, x.surname, x.lastname);  // print person using the structs data
}
