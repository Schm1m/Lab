// header file for `printf, scanf` is missing
   #include <stdio.h>

double square(double a) {
	a *= a;
	return a;  // missing semicolon ;
}

// integer is not a data type in C should be `int main`
int main(int argc, char *argv[]) {
	double zahl;
	printf("Geben Sie eine Zahl ein: "); // defined in <stdio.h>

	// scanf needs an address to write into `scanf("%lf", &zahl);`
	scanf("%lf", &zahl); // defined in <stdio.h>

	// square <=> (*square) <=> (*****square)...
	// double (*S) (double) = square; (*S) <=> S <=> square ...

	double (*S) (double) = square;
	printf("\n%.2lf²=%.2lf", zahl, (*square)(zahl)); // missing ) before the semicolon
	printf("\n%.2lf²=%.2lf", zahl, square(zahl));
	printf("\n%.2lf²=%.2lf", zahl, (********square)(zahl));
	printf("\n%.2lf²=%.2lf", zahl, (*S)(zahl));
	printf("\n%.2lf²=%.2lf", zahl, (***S)(zahl));
	printf("\n%.2lf²=%.2lf", zahl, S(zahl));

	// dereferencing a function or even a function pointer,
	//    can be doe AS MANY TIME AS YOU WANT!
	// the result is always the same. Just a pointer to the code block,
	//    where the function is defined in memory
	// It is as futile , as me trying to understand `Elektrotechnik` :(.
	return 0;
}

