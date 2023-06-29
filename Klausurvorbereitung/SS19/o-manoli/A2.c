#include <stdio.h>

typedef struct{

	double x;
	double y;
	double z;

}Vector;

double e = 1e-7;      // 10^-7

int isOrthogonal(Vector a, Vector b)
{
	double dot = a.x * b.x + a.y * b.y + a.z * b.z;

	dot = (dot < 0) ? -dot : dot;	// abs

	return dot <= e; // floating point arithmetic is never precise
}

int main(){

	Vector v1 = {-1, 0, 0};
	Vector v2 = {1, 1, 0};

	printf("isOrthogonal(): %d\n", isOrthogonal(v1, v2));

	return 0;
}
