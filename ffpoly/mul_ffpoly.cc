/* File: mul_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

ffpoly
ffpoly::operator*(ffpoly const &p)
{ //Naive convolution calculation
	if (characteristic != p.characteristic)
	{
		throw std::runtime_error(
			"Characteristics must match to perform arithmetic");
	}
	ffpoly newpoly(characteristic);
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

ffpoly
ffpoly::const_mul(unsigned long long c)
{ //Compute c*p where p is our polynomial.
	ffpoly newpoly(*this);
	for (unsigned long long i = 0; i <= deg; i++)
	{
		newpoly.coef[i] = (coef[i]*c) % characteristic;
	}
	return newpoly;
}

ffpoly
ffpoly::monic_shift(unsigned long long n)
{ //Compute x^n * p where p is our polynomial.
	ffpoly newpoly(characteristic);
	newpoly.deg = deg + n;
	newpoly.coef.resize(n, 0);
	newpoly.coef.insert(newpoly.coef.end(), coef.begin(), coef.end());
	return newpoly;
}
