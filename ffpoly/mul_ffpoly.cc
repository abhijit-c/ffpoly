/* File: mul_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

ffpoly
ffpoly::operator*(ffpoly const &p)
{ //Naive convolution calculation
	ffpoly newpoly(std::min(p.characteristic, characteristic));
	newpoly.deg = p.deg + deg;
	newpoly.coef[0] = coef[0]*p.coef[p.deg] % newpoly.characteristic;
	for (unsigned long long i=1; i <= newpoly.deg; i++)
	{
		newpoly.coef.push_back(0);
		for (unsigned long long j = 0; j <= i; j++)
		{
			newpoly.coef[i] += get_term(j)*p.get_term(i-j);
		}
		newpoly.coef[i] %= newpoly.characteristic;
	}
	return newpoly;
}
