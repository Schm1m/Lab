// cody by tim, L7Q3

void ownStrcpy(char a[], char b[]) {
    int i = 0;
    while (b[i] != '\0') {  // copy all content to the new char array
        a[i] = b[i];
        i++;
    }
    while (i < 40) {  // overwrite the rest of the char array with "nothing"
        a[i] = '\0';
        i++;
    }
}
