// cody by tim, L7Q1

int minimum(int *a, int l) {
    int lowest;
    lowest = a[0];                 // predefine first element as lowest ( 0 would work if there is an element < 0 )
    for (int i = 1; i < l; i++) {  // iterate through all elements to find a smaller one
        if (a[i] < lowest)
            lowest = a[i];
    }
    return lowest;  // return the smallest element
}