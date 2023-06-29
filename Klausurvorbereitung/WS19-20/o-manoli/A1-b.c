#include <stdio.h>
#include <string.h>

int main(){

	int v1, v2;
	char feld[] = "1234WVXYZ"; // 1234 XYZ WV = 9
	v1 = sizeof feld;		// including '\0' -> 10
	v2 = strlen(feld);	// just 9 chars without \0'

	printf("v1: %d\n", v1);
	printf("v2: %d\n", v2);

	return 0;
}

