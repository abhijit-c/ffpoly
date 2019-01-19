/* ffpoly class header file
 * File Name: ffpoly.h
 * Author: Abhijit Chowdhary */
#ifndef FFPOLY_H
#define FFPOLY_H

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

class ffpoly
{
    public:
        // Fields
        std::vector<unsigned long long> coef;
        unsigned long long deg;
        unsigned long long characteristic;

        // Constructors and Destructors: ffpoly.cc
        ffpoly();
        ffpoly(unsigned long long);
        ffpoly(std::vector<unsigned long long>, unsigned long long, unsigned long long);
        ffpoly(unsigned long long[], unsigned long long, unsigned long long);
        ffpoly(ffpoly&);
        ~ffpoly() 
        { 
            coef.clear(); coef.shrink_to_fit(); 
            deg = 0;
            characteristic = 0;
        }

        //Getters and Setters
        long long get_term(unsigned long long) const;
        void set_term(unsigned long long, long long);

        // Operators
        ffpoly operator+(ffpoly const &); 
        ffpoly operator-(); 
        ffpoly operator-(ffpoly const &); 
        ffpoly operator*(ffpoly const &); 
        long long operator()(long long); 

        //Useful Tools
        //ffpoly diff(ffpoly &, unsigned long long);
        //ffpoly integrate(ffpoly &, unsigned long long);
        //std::vector<ffpoly> factor();

        // Presentation
        void print_poly();
	private:
		void shrink_to_fit(ffpoly &);
};
#endif
