// cody by tim, L6Q11
int weekday(int d, int m, int y) {
    int unixZero = 4;                                                        // unix time 0 (1.1.1970) was a thursday
    int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // define days of each month

    int deltaY = (y - 1970) * 365;  // calculate the year based day difference between unix time 0 and the given date
    int deltaM = 0;                 // initialise deltaM (month based difference)
    for (int i = 1; i < m; i++) {   // calculate the month based difference unsing the length of each month
        deltaM += monthLength[i - 1];
    }
    int deltaD = (d - 1);              // set the day difference
    int leap = 0;                      // init leap
    int nowLeap = 0;                   // init nowLeap
    for (int i = 1970; i <= y; i++) {  // count the number of leap years between the given date and unix 0
        if (i % 4 == 0) {              // its a leap year if its devidable by 4
            if (i % 100 == 0) {        // but not if its dividable by 100
                if (i % 400 == 0) {    // but it is if its dividable by 400
                    leap++;
                    nowLeap = 1;
                }
            } else {
                leap++;
                nowLeap = 1;
            }
        } else {
            nowLeap = 0;
        }
    }
    if (nowLeap == 1 && deltaD + deltaM <= 57) {  // subtract 1 if the given date is before 29.02 ( if its a leap year )
        leap--;
    }
    int test = (deltaD + deltaM + deltaY + leap + unixZero) % 7;  // add everything up and get the weekday with % 7
    return test;
}