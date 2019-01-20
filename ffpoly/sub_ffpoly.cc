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
	for (unsigned long long i = newpoly.deg; i > 0; i--)
	{
		unsigned long long v = (get_term(i)-p.get_term(i)) 
							   % newpoly.characteristic;
		if (v == 0)
		{
			newpoly.coef.pop_back(); newpoly.deg--;
		}
		else
		{
			newpoly.coef[i] = v;
		}
	}
	newpoly.coef[0] = (coef[0] - p.coef[0]) % newpoly.characteristic;
	return newpoly;
}
