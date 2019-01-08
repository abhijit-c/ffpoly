/* File: ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

// Constructors
ffpoly::ffpoly()
{
	deg = 0;
	coef.push_back(0);
	characteristic = ULLONG_MAX;
}

ffpoly::ffpoly(long long c)
{
	deg = 0;
	coef.push_back(0);
	characteristic = c;
}

ffpoly::ffpoly(long long poly[], long long d)
{
	deg = d;
	coef.insert(coef.end(), &poly[0], &poly[d+1]);
	characteristic = ULLONG_MAX;
}

ffpoly::ffpoly(long long poly[], long long d, long long c)
{
	deg = d;
	coef.insert(coef.end(), &poly[0], &poly[d+1]);
	characteristic = c;
}

//Destructor
ffpoly::ffpoly(ffpoly& poly)
{
	deg = poly.deg;
	coef.insert(coef.end(), poly.coef.begin(), poly.coef.end()); 
	characteristic = poly.characteristic;
}
