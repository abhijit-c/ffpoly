#include <iostream>
#include "ffpoly/ffpoly.h"

void test_eval();
void test_mul();
void test_add();

int main()
{
	test_eval();
    test_mul();
    test_add();
}

void test_eval()
{
	long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	ffpoly p_1(arr_1, 6, 7);
	for (long long i = 0; i < 7; i++)
	{
		std::cout << p_1(i) << ",";
	}
	std::cout << '\n' << "Answer: [1,0,1,1,1,1,1]" << std::endl;
}

void test_mul()
{
	long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	long long arr_2[2] = {-1, 1};
	ffpoly p_1(arr_1, 6, 7);
	ffpoly p_2(arr_2, 1, 7);
	p_1.print_poly();
	p_2.print_poly();
	(p_1 * p_2).print_poly();
}

void test_add()
{
	long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	long long arr_2[7] = {-1, -1, -1, -1, -1, -1, -1};
	ffpoly p_1(arr_1, 6, 7);
	ffpoly p_2(arr_2, 6, 7);
	p_1.print_poly();
	p_2.print_poly();
	(p_1 + p_2).print_poly();
}
