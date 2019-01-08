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
        std::vector<long long> coef;
        unsigned long long deg;
        unsigned long long characteristic;

        // Constructors and Destructors: ffpoly.cc
        ffpoly();
        ffpoly(long long);
        ffpoly(long long[], long long);
        ffpoly(long long[], long long, long long);
        ffpoly(ffpoly&);
        ~ffpoly() 
        { 
            coef.clear(); coef.shrink_to_fit(); 
            deg = 0;
            characteristic = ULLONG_MAX;
        }

        //Getters and Setters
        long long get_term(unsigned long long) const;
        void set_term(unsigned long long, long long);

        // Operators
        ffpoly operator+(ffpoly const &); 
        ffpoly operator-(); 
        ffpoly operator-(ffpoly const &); 
        ffpoly operator*(ffpoly const &); 
        ffpoly operator()(long long); 

        // Presentation
        void print_poly();
};
#endif
