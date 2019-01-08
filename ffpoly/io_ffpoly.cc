/* File: io_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

// Presentation
void 
ffpoly::print_poly()
{
	for (long long i = deg; i > 0; i--)
	{
		std::string sgn = (coef[i-1] >= 0) ? " + " : " - ";
		std::string xpow = (i == 1) ? "x" : "x^" + std::to_string(i);
		std::string c = (coef[i]==1) ? "" : std::to_string(std::abs(coef[i]));
		std::cout << c << xpow << sgn;
	}
	std::string cmod = (characteristic == ULLONG_MAX) ? 
		"" : 
		" (mod " + std::to_string(characteristic) + ")"; 
	std::cout << std::abs(coef[0]) << cmod << std::endl;
}
