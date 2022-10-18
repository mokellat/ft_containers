// #include "./vector/vector.hpp"
#include <vector>
#include <iostream>

typedef std::vector<int> VE_INT;
#define myprint(Y) std::cout << Y << std::endl 


void	print_vector(VE_INT ve)
{
	for(size_t i = 0; i < ve.size(); i++)
	{
		myprint(ve[i]);
	}
}

void	print_vector_iter_inc(VE_INT ve)
{
	VE_INT::iterator it = ve.begin();
	for(; it != ve.end(); it++)
	{
		myprint(*it);
	}
}

void	print_vector_iter_dec(VE_INT ve)
{
	VE_INT::iterator it = ve.end();
	for(--it; it != ve.begin(); it--)
	{
		myprint(*it);
	}
}

void	print_vector_iter_rev_it_inc(VE_INT ve)
{
	VE_INT::reverse_iterator it = ve.rend();
	for(--it; it != ve.rbegin(); it--)
	{
		myprint(*it);
	}
}

void	print_vector_iter_rev_it_dec(VE_INT ve)
{
	VE_INT::reverse_iterator it = ve.rbegin();
	for(; it != ve.rend(); it++)
	{
		myprint(*it);
	}
}

int main()
{
	// default construction-------------------------------------------------------------------
	// VE_INT ve;

	//(1)-------------------------------------------------------------------------------------
	// VE_INT ve1(10, 5);

	// for(size_t i= 0; i < ve1.size(); i++)
	// 	myprint(ve1[i]);

	//(2)------------------------------------------------------------------------------------
	// VE_INT ve1(10, 5);
	// VE_INT ve2(ve1.begin(), ve1.end());
	// print_vector(ve2);
	// print_vector_iter_inc(ve2);
	// print_vector_iter_dec(ve2);

	//(3)------------------------------------------------------------------------------------
	// VE_INT ve3(5,10);
	// VE_INT ve4(ve3);
	// print_vector(ve4);
	// print_vector_iter_inc(ve4);
	// print_vector_iter_dec(ve4);

	//asignement overload--------------------------------------------------------------------
	// VE_INT ve5(100, -1);
	// VE_INT ve6 = ve5;
	// print_vector(ve6);
	// print_vector_iter_inc(ve6);
	// print_vector_iter_dec(ve6);

	//reverse iterators----------------------------------------------------------------------
	// VE_INT ve7(10, 10);
	// // print_vector_iter_rev_it_inc(ve7);
	// print_vector_iter_rev_it_dec(ve7);

	// VE_INT first;

	// first.assign (7,100);             // 7 ints with a value of 100
	// print_vector(first);

	VE_INT myvector;
	// int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	print_vector(myvector);
	// while (!myvector.empty())
	// {
	// 	sum+=myvector.back();
	// 	myvector.pop_back();
	// }
	myprint("------------");
	myvector.pop_back();
	print_vector(myvector);
	myprint("------------");
	myvector.pop_back();
	print_vector(myvector);
	myprint("------------");
	myvector.pop_back();
	print_vector(myvector);
}