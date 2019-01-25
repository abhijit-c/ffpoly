/* File: eucdiv_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

/*
std::vector<ffpoly>
ffpoly::operator/(ffpoly const &p)
{
	std::vector<ffpoly> div;
	if (characteristic != p.characteristic)
	{
		throw std::runtime_error(
			"Characteristics must match to perform arithmetic");
	}
	else if (p.deg == 0 && p.get_term(0) == 0)
	{
		throw std::runtime_error(
			"Division by zero polynomial");
	}
	ffpoly q(characteristic);
	ffpoly r(*this);
	unsigned long long c = minv(p.lc());
	while (r.deg >= p.deg)
	{
		ffpoly s(characteristic); s.set_term(r.deg-p.deg, r.lc()*c);
		q = q + s;
		r = r - s*p;
	}
	div.push_back(q); div.push_back(r);
	return div;
}
*/

std::vector<ffpoly>
ffpoly::operator/(ffpoly const &p)
{
	if (characteristic != p.characteristic)
	{
		throw std::runtime_error(
			"Characteristics must match to perform arithmetic");
	}
	else if (p.deg == 0 && p.get_term(0) == 0)
	{
		throw std::runtime_error(
			"Division by zero polynomial");
	}
	std::vector<ffpoly> div;
	ffpoly q(characteristic); ffpoly r(*this);
}
