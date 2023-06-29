#include <stdio.h>

int main()
{
	int arr[2][3][2] = {{{1, 1}, {2, 2}, {3, 3}}, {{4, 4}, {5, 5}, {6, 6}}};

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){
				printf("%d\n", arr[i][j][k]);
			}
		}
	}

	printf("\n- - - - -\n\n");

	int n = 2*3*2;

	for (int *index = arr[0][0]; n-- > 0; index++){
		printf("%d\n", *index);
	}
}
