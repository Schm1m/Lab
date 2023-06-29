#include <stdio.h>

void echo(char cArr[])
{
	printf("%s", cArr);
}

int main(void)
{
	char cArr[10];
	printf("Eingabe: ");
	scanf("%s", cArr);
	echo(cArr);
	return 0;
}

