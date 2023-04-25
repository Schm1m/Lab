// cody by tim, L6Q11, but the way its intended to be done

int weekday(int d, int m, int y) {
    return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
    /*  the code AND explanation ist just written out in c  *
     *  on the english wiki page, cited in the question     */
}