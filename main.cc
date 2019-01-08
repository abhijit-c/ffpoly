#include <iostream>
#include "ffpoly/ffpoly.h"

int main()
{
    long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
    long long arr_2[2] = {-1, 1};
    ffpoly p_1(arr_1, 6, 7);
    ffpoly p_2(arr_2, 1, 7);
    p_1.print_poly();
    p_2.print_poly();
    (p_1 * p_2).print_poly();
}
