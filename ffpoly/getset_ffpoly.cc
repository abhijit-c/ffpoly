/* File: getset_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

//Getters and Setters
/* The reason as to why I bothered with getters and setters is to have nice
 * behavior when I ask for a the value of a term out of the range of the
 * ffpoly. This makes the code in the operators a little nicer.
 */
long long 
ffpoly::get_term(unsigned long long d) const
{
	if (d <= deg) { return coef[d]; }
	else { return 0; }
}

void 
ffpoly::set_term(unsigned long long d, long long new_c)
{
	if (d <= deg) { coef[d] = new_c; }
	else { coef.resize(d+1, 0); deg = d; coef[d] = new_c; }
}
