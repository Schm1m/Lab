// cody by tim, L7Q4

void append(char a[], char b[]) {
    int i = 0;
    int j = 0;
    while (a[i] != '\0') {  // skip the already written string
        i++;
    }
    while (b[j] != '\0') {  // write b on a ( behind the already written part )
        a[i] = b[j];
        i++;
        j++;
    }
}