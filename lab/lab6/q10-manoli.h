/*
	Author: Manoli
*/

int prime(int x)
{

	// if --> do otherwise do-nothing

	// -inf ... -1, 0, 1 ==> not prime
	if (x < 2)
		return 0;

	// 2 is a prime
	if (x == 2)
		return 1;

	// x % n == 0 --> n is a factor

	if (!(x % 2))
		return 0;

	// already know that 2 is not a factor!
	int i = 3, threshold = x / 2;

	// critical case x = 3 --> threshold = 1 ==> no-loop
	// x%x will never run

	while (i < threshold)
	{

		// i is factore ==> not prime
		if (!(x % i))
			return 0;

		// unfug but works2
		// if (!(x%(i+=2))) return 0;

		i += 2; // consider only odd numbers
	}

	// is prime
	return 1;
}
