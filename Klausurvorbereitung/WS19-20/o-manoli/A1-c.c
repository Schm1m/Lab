#include <stdio.h>
#include <string.h>

int main()
{

	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;

	// rot, blau, gruen, gelb
	for (blume = rot; blume <= gelb; blume++)
	{
		if (blume == rot)				printf("Farbe rot\n");
		else if (blume == blau)		printf("Farbe blau\n");
		else								printf("andere Farbe\n");
	}

	return 0;
}
