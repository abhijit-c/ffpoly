/* File: private_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

// Private Utility Functions
void 
ffpoly::shrink_to_fit(ffpoly& f)
{ //Use to remove trailing zeroes after computation.
	while (f.deg > 0 && f.coef[deg] == 0)
	{
		f.coef.pop_back();
		deg--;
	}
}
