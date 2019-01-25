/* File: eval_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

/* Evaluation of polynomial takes place via Horner's Rule, i.e.
 * f(x) = a_0 + a_1 x + ... + a_n x^n
 *      = a_0 + x(a_1 + x(a_2 + ... + x(a_{n-1} + x(a_n)) ... )) 
 */
unsigned long long
ffpoly::operator()(unsigned long long x)
{ 
	unsigned long long total = coef[deg];
	for (unsigned long long i = deg; i > 0; i--)
	{
		total = (total*x + coef[i-1]) % characteristic;
	}
	return total;
}
