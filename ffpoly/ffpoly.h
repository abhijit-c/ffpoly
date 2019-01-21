/* ffpoly class header file
 * File Name: ffpoly.h
 * Author: Abhijit Chowdhary */
#ifndef FFPOLY_H
#define FFPOLY_H

#include <algorithm>
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

        //Getters and Setters
        unsigned long long get_term(unsigned long long) const;
        void set_term(unsigned long long, unsigned long long);

        // Operators
        ffpoly operator+(ffpoly const &); 
        ffpoly operator-(); 
        ffpoly operator-(ffpoly const &); 
        ffpoly operator*(ffpoly const &); 
		ffpoly& operator=(ffpoly const &);
        unsigned long long operator()(unsigned long long); 

        //Useful Tools
        ffpoly diff(unsigned long long);
        //ffpoly integrate(ffpoly &, unsigned long long);
        //std::vector<ffpoly> factor();

        // Presentation
        void print_poly();
};
#endif
