/* File: ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

//Unary negation
ffpoly 
ffpoly::operator-()
{
	ffpoly newpoly(characteristic);
	newpoly.deg = deg;
	newpoly.coef[0] = -coef[0];
	for (unsigned long long i = 0; i <= newpoly.deg; i++)
	{
		newpoly.coef.push_back(-coef[i]);
	}
	return newpoly;
}

//Standard subtraction.
ffpoly 
ffpoly::operator-(ffpoly const &p)
{
	ffpoly newpoly(std::min(p.characteristic, characteristic));
	newpoly.set_term(std::max(p.deg, deg), 0); //Internally resizes coef
	unsigned long long thresh = std::min(p.deg, deg);
	for (unsigned long long i = 0; i <= thresh; i++)
	{ //Avoiding checks to see if coef[i] is defined
		newpoly.coef[i] = (coef[i] - p.coef[i]) % newpoly.characteristic;
	}
	if (p.deg < deg)
	{
		for (unsigned long long i = thresh + 1; i <= newpoly.deg; i++)
		{
			newpoly.coef[i] = coef[i] % newpoly.characteristic;
		}
	}
	else
	{
		for (unsigned long long i = thresh + 1; i <= newpoly.deg; i++)
		{
			newpoly.coef[i] = -p.coef[i] % newpoly.characteristic;
		}
	}
	return newpoly;
}
