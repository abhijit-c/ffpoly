/* File: eucdiv_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

std::vector<ffpoly>
ffpoly::operator/(ffpoly const &p)
{
	std::vector<ffpoly> div;
	if (characteristic != p.characteristic)
	{
		throw std::runtime_error(
			"Characteristics must match to perform arithmetic");
	}
	ffpoly q(characteristic);
	ffpoly r(*this);
	unsigned long long c = minv(p.lc());
	while (r.deg >= p.deg)
	{
		ffpoly s( const_mul(r.lc()*c) );
		s = s.monic_shift(r.deg - p.deg) ;
		q = q + s;
		r = r - s*p;
	}
	div.push_back(q); div.push_back(r);
	return div;
}
