// cody by tim, L7Q2
void toUpper(char a[]) {
    int i = 0;
    while (a[i] != '\0') {  // do untill end of char array
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;  // lower char value by 32 to make it uppercase, if it isn´t already
        }
        i++;
    }
}