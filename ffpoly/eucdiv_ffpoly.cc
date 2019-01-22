/* File: eucdiv_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

std::vector<ffpoly>
ffpoly::operator/(ffpoly const &p)
{
	std::vector<ffpoly> div;
	if (characteristic != p.characteristic)
	{
		throw runtime_error("Characteristics must match to perform arithmetic");
	}
	ffpoly q(characteristic);
	ffpoly r = this;
	unsigned long long c = p.lc();
}
