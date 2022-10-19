#include "./vector/vector.hpp"
#include <sys/time.h>
#include <vector>

typedef ft::vector<int> VE_INT;
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

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
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
	// print_vector_iter_rev_it_inc(ve7);
	// print_vector_iter_rev_it_dec(ve7);

	//size----------------------------------------------------------------------------------
	// VE_INT ve8;
	// VE_INT ve9(10);
	// VE_INT ve10(5, 8);
	// VE_INT ve11(ve9);
	// VE_INT ve12 = ve10;
	// VE_INT ve13(ve11.begin(), ve11.begin() + 3);

	// myprint(ve8.size());
	// myprint(ve9.size());
	// myprint(ve10.size());
	// myprint(ve11.size());
	// myprint(ve12.size());
	// myprint(ve13.size());


	// constructors-------------------------------------------------------------------------
	// VE_INT first;                                // empty vector of ints
	// VE_INT second (4,100);                       // four ints with value 100
	// VE_INT third (second.begin(),second.end());  // iterating through second
	// VE_INT fourth (third);                       // a copy of third

	// // the iterator constructor can also be used to construct from arrays:
	// int myints[] = {16,2,77,29};
	// VE_INT fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// std::cout << "The contents of fifth are:";
	// for (VE_INT::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	//opearator=-----------------------------------------------------------------------
	// VE_INT foo (3,0);
	// VE_INT bar (5,0);

	// bar = foo;
	// foo = VE_INT();

	// std::cout << "Size of foo: " << int(foo.size()) << '\n';
	// std::cout << "Size of bar: " << int(bar.size()) << '\n';

	//resize--------------------------------------------------------------------------------
	// VE_INT myvector;

	// // set some initial content:
	// for(int i = 1; i < 10; i++) 
	// 	myvector.push_back(i);

	// myvector.resize(5);
	// myvector.resize(8,100);
	// myvector.resize(12);

	// std::cout << "myvector contains:";
	// for (size_t i=0; i < myvector.size(); i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	//capacity------------------------------------------------------------------------------
	// VE_INT myvector;

  	// // set some content in the vector:
	// for (int i = 0; i < 100; i++) 
	// 	myvector.push_back(i);
	// std::cout << "size: " << (int) myvector.size() << '\n';
	// std::cout << "capacity: " << (int) myvector.capacity() << '\n';


	//empty----------------------------------------------------------------------------------
	// VE_INT	myvector;
	// int sum (0);

	// for (int i=2;i<=10;i++) 
	// 	myvector.push_back(i);
	// // print_vector(myvector);
	// while (!myvector.empty())
	// {
	// 	sum += myvector.back();
	// 	myvector.pop_back();
	// }
	// std::cout << "total: " << sum << '\n';

	//reserve---------------------------------------------------------------------------------
	// VE_INT::size_type sz;
	// VE_INT foo;
	// sz = foo.capacity();
	// std::cout << "making foo grow:\n";
	// for (int i=0; i<100; ++i) 
	// {
	// 	foo.push_back(i);
	// 	if (sz!=foo.capacity()) 
	// 	{
	// 		sz = foo.capacity();
	// 		std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// VE_INT bar;
	// sz = bar.capacity();
	// bar.reserve(100);   // this is the only difference with foo above
	// std::cout << "making bar grow:\n";
	// for (int i=0; i<100; ++i)
	// {
	// 	bar.push_back(i);
	// 	if (sz != bar.capacity())
	// 	{
	// 		sz = bar.capacity();
	// 		std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	//operator[]------------------------------------------------------------------------------
	// VE_INT myvector (10);   // 10 zero-initialized elements

	// VE_INT::size_type sz = myvector.size();

	// // assign some values:
	// for (unsigned i=0; i<sz; i++) 
	// 	myvector[i]=i;
	// // reverse vector using operator[]:
	// for (unsigned i=0; i<sz/2; i++)
	// {
	// 	int temp;
	// 	temp = myvector[sz-1-i];
	// 	myvector[sz-1-i]=myvector[i];
	// 	myvector[i]=temp;
	// }

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<sz; i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	//at -------------------------------------------------------------------------------------
	// VE_INT myvector (10);   // 10 zero-initialized ints

	// // assign some values:
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	myvector.at(i)=i;
	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	std::cout << ' ' << myvector.at(i);
	// std::cout << '\n';

	// front ---------------------------------------------------------------------------------
	// VE_INT myvector;

	// myvector.push_back(78);
	// myvector.push_back(16);

	// // now front equals 78, and back 16

	// myvector.front() -= myvector.back();

	// std::cout << "myvector.front() is now " << myvector.front() << '\n';


	// back -----------------------------------------------------------------------------------
	// VE_INT myvector;

	// myvector.push_back(10);
	// while (myvector.back() != 0)
	// {
	// 	myvector.push_back ( myvector.back() -1 );
	// }
	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size() ; i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// assign --------------------------------------------------------------------------------
	// VE_INT first;
	// VE_INT second;
	// VE_INT third;

	// first.assign (7,100);             // 7 ints with a value of 100
	// VE_INT::iterator it;
	// it = first.begin()+1;

	// second.assign (it,first.end()-1); // the 5 central values of first
	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);   // assigning from array.

	// std::cout << "Size of first: " << int (first.size()) << '\n';
	// std::cout << "Size of second: " << int (second.size()) << '\n';
	// std::cout << "Size of third: " << int (third.size()) << '\n';

	//push_back -------------------------------------------------------------------------------
	// VE_INT myvector;
	// int myint;
	// int i =-1;

	// std::cout << "Please enter some integers (enter 0 to end):\n";

	// do {
	// 	std::cin >> myint;
	// 	myvector.push_back (myint);
	// 	++i;
	// } while (myint && i < 4);

	// std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	// print_vector(myvector);

	// pop_back ------------------------------------------------------------------------------
	// VE_INT myvector;
	// int sum (0);
	// myvector.push_back (100);
	// myvector.push_back (200);
	// myvector.push_back (300);
	// // print_vector(myvector);
	// while (!myvector.empty())
	// {
	// 	sum+=myvector.back();
	// 	myvector.pop_back();
	// }
	// myprint("------------");
	// myvector.pop_back();
	// print_vector(myvector);
	// myprint("------------");
	// myvector.pop_back();
	// print_vector(myvector);
	// myprint("------------");
	// myvector.pop_back();
	// print_vector(myvector);

	// std::cout << "The elements of myvector add up to " << sum << '\n';

	// insert --------------------------------------------------------------------------------
	// VE_INT myvector (3,100);
	// VE_INT::iterator it;

	// it = myvector.begin();
	// it = myvector.insert ( it , 200 );

	// myvector.insert (it,2,300);

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// VE_INT anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it != myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	//erase ---------------------------------------------------------------------------------
	// VE_INT myvector;

	// // set some values (from 1 to 10)
	// for (int i=1; i<=10; i++) 
	// 	myvector.push_back(i);
	// // erase the 6th element
	// myvector.erase (myvector.begin()+5);
	// // print_vector(myvector);

	// // erase the first 3 elements:
	// myvector.erase (myvector.begin(), myvector.begin() + 3);

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); ++i)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	//swap-----------------------------------------------------------------------------------
	// VE_INT foo (3,100);   // three ints with a value of 100
	// VE_INT bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (unsigned i=0; i<foo.size(); i++)
	// 	std::cout << ' ' << foo[i];
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (unsigned i=0; i<bar.size(); i++)
	// 	std::cout << ' ' << bar[i];
	// std::cout << '\n';

	//get_allocator---------------------------------------------------------------------------
	// VE_INT myvector;
	// int * p;
	// unsigned int i;

	// // allocate an array with space for 5 elements using vector's allocator:
	// p = myvector.get_allocator().allocate(5);

	// // construct values in-place on the array:
	// for (i=0; i<5; i++) 
	// 	myvector.get_allocator().construct(&p[i],i);

	// std::cout << "The allocated array contains:";
	// for (i=0; i<5; i++) 
	// 	std::cout << ' ' << p[i];
	// std::cout << '\n';

	// // destroy and deallocate:
	// for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// myvector.get_allocator().deallocate(p,5);


	// operators test--------------------------------------------------------------------------
	// VE_INT foo (3,100);   // three ints with a value of 100
	// VE_INT bar (2,200);   // two ints with a value of 200

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	//non member swap -------------------------------------------------------------------------------------
	// VE_INT foo (3,100);   // three ints with a value of 100
	// VE_INT bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);

	// std::cout << "foo contains:";
	// for (VE_INT::iterator it = foo.begin(); it!=foo.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "bar contains:";
	// for (VE_INT::iterator it = bar.begin(); it!=bar.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// time test -------------------------------------------------------------------------------------------
	// time_t mystart = get_time();
    // VE_INT ve;
    // int size = 100000000;
    // for(int i = 1; i < size; i++)
    // {
    //     ve.push_back(i+1);
    // }
    // time_t myend = get_time();

    // myprint(myend - mystart);

    // time_t start = get_time();
    // std::vector<int> ve1;
    // for(int i = 1; i < size; i++)
    // {
    //     ve1.push_back(i+1);
    // }
    // time_t end = get_time();

    // myprint(end - start);
	// print_vector(ve);

	//comparaison const iterators and iterators---------------------------------------------------------------
	// VE_INT ve;
	// for(int i = 0; i < 10; i++)
	// 	ve.push_back(i);
	// VE_INT::iterator it = ve.begin();
	// VE_INT::const_iterator ite = (ve.begin() + 3);

	// if(ite > it)
	// 	puts("true");
	// else
	// 	puts("false");

  return 0;
}