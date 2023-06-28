#include <stdio.h>
#include <string.h>

int main()
{
	char feld[15] = "VWXYZ123";
	int m = strlen(feld); // 123 XYZ VW = 8
	feld[m / 2] = '\0';	 // 8/2 = 4	'\0'
	// truncates the string at the index 4
	printf("%4i\n%s", m, feld);
	//   8
	//VWXY
	return 0;
}

