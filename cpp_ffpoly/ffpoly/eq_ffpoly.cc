/* File: eq_ffpoly.cc
 * Author: Abhijit Chowdhary */
#include "ffpoly.h"

ffpoly&
ffpoly::operator=(ffpoly const &p)
{ 
	if (this == &p) { return *this; } //Self-assignment guard
	coef = p.coef;
	deg = p.deg;
	characteristic = p.characteristic;
	return *this;
}
