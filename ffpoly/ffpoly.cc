/* File: ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

// Constructors
ffpoly::ffpoly(unsigned long long c)
{
	deg = 0;
	coef.push_back(0);
	characteristic = c;
}

ffpoly::ffpoly(std::vector<unsigned long long> p, unsigned long long c)
{
	deg = p.size() - 1;
	coef.insert(coef.end(), p.begin(), p.end());
	characteristic = c;
}

ffpoly::ffpoly(unsigned long long poly[], 
			   unsigned long long d, 
			   unsigned long long c)
{
	deg = d;
	coef.insert(coef.end(), &poly[0], &poly[d+1]);
	characteristic = c;
}

ffpoly::ffpoly(ffpoly &poly)
{
	deg = poly.deg;
	coef.insert(coef.end(), poly.coef.begin(), poly.coef.end()); 
	characteristic = poly.characteristic;
}

ffpoly::ffpoly(ffpoly const &poly)
{
	deg = poly.deg;
	coef.insert(coef.end(), poly.coef.begin(), poly.coef.end()); 
	characteristic = poly.characteristic;
}
