/* File: diff_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

ffpoly
ffpoly::diff(unsigned long long n)
{ 
	ffpoly diffpoly(characteristic);
	if (n > deg) { return diffpoly; }
	diffpoly.deg = deg - n;
	unsigned long long v = 1;
	for (unsigned long long i = 2; i <= n; i++) { v*= i; }
	diffpoly.coef[0] = v*coef[n] % characteristic;
	for (unsigned long long i = n+1; i <= deg; i++)
	{
		v = (v * i) / (i - n);
		diffpoly.coef.push_back(v*coef[i]);
	}
	return diffpoly;
}
