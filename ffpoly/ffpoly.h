/* ffpoly class header file
 * File Name: ffpoly.h
 * Author: Abhijit Chowdhary */
#ifndef FFPOLY_H
#define FFPOLY_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class ffpoly
{
    public:
        // Fields
        std::vector<unsigned long long> coef;
        unsigned long long deg; unsigned long long characteristic;

        // Constructors and Destructors: ffpoly.cc
        ffpoly(unsigned long long);
        ffpoly(std::vector<unsigned long long>, unsigned long long);
        ffpoly(unsigned long long[], unsigned long long, unsigned long long);
        ffpoly(ffpoly&);
        ~ffpoly() 
        { 
            coef.clear(); coef.shrink_to_fit(); 
            deg = 0;
            characteristic = 0;
        }

		ffpoly& operator=(ffpoly const &);

        //Getters and Setters
        unsigned long long get_term(unsigned long long) const;
		unsigned long long lc() const;
        void set_term(unsigned long long, unsigned long long);

        // Operations on polynomial
        ffpoly operator+(ffpoly const &); 
        ffpoly operator-(); 
        ffpoly operator-(ffpoly const &); 

        ffpoly operator*(ffpoly const &); 
		ffpoly const_mul(unsigned long long);
		ffpoly monic_shift(unsigned long long);

		std::vector<ffpoly> operator/(ffpoly const &); 

        unsigned long long operator()(unsigned long long); 

        ffpoly diff(unsigned long long);

		//Tools for F_p
		unsigned long long fpexp(unsigned long long, unsigned long long) const;
		unsigned long long minv(unsigned long long) const;

        // Presentation
        void print_poly();
};
#endif
