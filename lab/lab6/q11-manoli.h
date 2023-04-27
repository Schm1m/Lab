/*
	Author: Manoli
*/

int weekday(int d, int m, int y)
{

	// Zeller's congruence

	// weekday is a number! (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)

	/*

	if (m < 3):
		d += y
		y -= 1
	else:
		d += y -2

	weekday = (d + 23*m/9 + 4 + y/4 - y/100 + y/400) % 7

	- - - - - - - - - - - - - - - - - - - - -

	branch 1.	<== x > 3 is True

		weekday = (d + y + 23*m/9 + 4 + (y-1)/4 - (y-1)/100 + (y-1)/400)%7

	branch 2. <== x > 3 is False

		weekday = (d + y + 23*m/9 + 4 -2 + y/4 - y/100 + y/400)%7

	the only difference is:

		`(y-1)/4 - (y-1)/100 + (y-1)/400`

		`-2 + y/4 - y/100 + y/400`

	*/

	// #branchless
	return (

			d

			+ y

			+ 23 * m / 9

			+ 4

			// first branch
			+ (m < 3) * ((y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400)

			// second brach ==> `a + !a` can't both be true
			+ (!(m < 3)) * (-2 + y / 4 - y / 100 + y / 400)

		) % 7
	;
}
