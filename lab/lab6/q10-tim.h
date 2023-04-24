// cody by tim, L6Q10
int prime(int a) {
    for (int i = 2; i * i < a; i++) {  // search for factors of the given number, end if the factor squared is higher than the given number
        if (a % i == 0) {              // break as soon as a matching factor is found
            return 0;                  // return 0 if its not a prime ( false )
        }
    }
    return 1;  // return 1 if it is a prime ( true )
}