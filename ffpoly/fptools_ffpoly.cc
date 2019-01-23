/* File: fptools_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

unsigned long long
ffpoly::fpexp(unsigned long long x, unsigned long long n)
{ //Computes x^a (mod characteristic)
	if (n == 1) { return 1; }
	unsigned long long y = 1;
	while (n > 0)
	{
		if (n % 2 == 1) { y = (y*x) % characteristic; }
		x = (x*x) % characteristic;
		n /= 2;
	}
	return y;
}

unsigned long long
ffpoly::minv(unsigned long long x)
{ //Using Euler's theorem $x^{\phi(m)} \equiv 1 \mod{m}$
	return fexp(x, characteristic - 2);
}
