/* File: io_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

// Presentation
void 
ffpoly::print_poly()
{
	for (unsigned long long i = deg; i > 0; i--)
	{
		std::string sgn = (coef[i-1] >= 0) ? " + " : " - ";
		std::string xpow = (i == 1) ? "x" : "x^" + std::to_string(i);
		std::string c = (coef[i]==1) ? "" : std::to_string(coef[i]);
		std::cout << c << xpow << sgn;
	}
	std::cout << coef[0] 
			  << " (mod " + std::to_string(characteristic) + ")" 
			  << std::endl;
}
