#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int weekday(int day, int month, int year) {

    /*
     * for the people who struggle...
     *
     * https://de.wikipedia.org/wiki/Wochentagsberechnung
     * https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
     * https://stackoverflow.com/questions/6054016/c-program-to-find-day-of-week-given-date
     */

    /*
     * stolen from wikipedia...
     * quite interesting...
     */
    return (day += month < 3 ? year-- : year - 2, 23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7;

    /*
     * the calculation with "year" checks for a leap year, months include feb.!
     * there is use of the "," operator, it's a binary operator and evaluates the first half
     * and then binds the second half. see: https://en.wikipedia.org/wiki/Comma_operator
     */

}

int main(void) {

    printf("%d", weekday(29, 04, 2021));

}