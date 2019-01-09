/* File: ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

ffpoly 
ffpoly::operator+(ffpoly const &p)
{
	ffpoly newpoly(std::min(p.characteristic, characteristic));
	newpoly.set_term(std::max(p.deg, deg), 0); //Internally resizes coef
	unsigned long long thresh = std::min(p.deg, deg);
	for (unsigned long long i = 0; i <= thresh; i++)
	{
		newpoly.coef[i] = (coef[i] + p.coef[i]) % newpoly.characteristic;
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
			newpoly.coef[i] = p.coef[i] % newpoly.characteristic;
		}
	}
	return newpoly;
}