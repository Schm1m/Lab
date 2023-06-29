#include <stdio.h>
#include <string.h>

int main()
{

	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;

	// rot, blau, gruen, gelb
	for (blume = rot; blume <= gelb; blume++)
	{
		switch(blume)
		{
			case rot:
				printf("Farbe rot\n");
				break;
			case blau:
				printf("Farbe blau\n");
				break;
			default:
				printf("andere Farbe\n");
		}
	}

	return 0;
}
