#include <iostream>
#include "ffpoly/ffpoly.h"

void test_eval();
void test_mul();
void test_add();
void test_diff();

int main()
{
	test_eval();
    test_mul();
    test_add();
	test_diff();
}

void test_eval()
{
	unsigned long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	ffpoly p_1(arr_1, 6, 7);
	for (unsigned long long i = 0; i < 7; i++)
	{
		std::cout << p_1(i) << ",";
	}
	std::cout << '\n' << "Answer: [1,0,1,1,1,1,1] \n" << std::endl;
}

void test_mul()
{
	unsigned long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	unsigned long long arr_2[2] = {6, 1};
	ffpoly p_1(arr_1, 6, 7);
	ffpoly p_2(arr_2, 1, 7);
	p_1.print_poly();
	p_2.print_poly();
	(p_1 * p_2).print_poly();
	std::cout << "Answer: x^7 + 1 (mod 7) \n" << std::endl;
}

void test_add()
{
	unsigned long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	unsigned long long arr_2[7] = {6, 6, 6, 6, 6, 6, 6};
	ffpoly p_1(arr_1, 6, 7);
	ffpoly p_2(arr_2, 6, 7);
	p_1.print_poly();
	p_2.print_poly();
	(p_1 + p_2).print_poly();
	std::cout << "Answer: 0 (mod 0) \n" << std::endl;
}

void test_diff()
{
	unsigned long long arr_1[7] = {1, 1, 1, 1, 1, 1, 1};
	ffpoly p_1(arr_1, 6, 100000);
	for (int i = 1; i <= 7; i++)
	{
		(p_1.diff(i)).print_poly();
	}
}
