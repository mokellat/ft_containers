// #include "./vector/vector.hpp"
#include <vector>
#include <iostream>

typedef std::vector<int> VE_INT;

int main()
{
    //default-----------------------------------
    // ft::vector<int> _ve;

    //(1)-----------------------------------
    // size_t n = 5;
    // ft::vector<int> _ve1(n, 10);

    // for (size_t i = 0; i < _ve1.size(); i++)
    //     std::cout << _ve1[i] << std::endl;

    // (2)-----------------------------------
	// int a1[7] = {10, 20, 30, 40, 50, 60, 70};

	// ft::vector<int> _ve2(a1, a1+7);

	//(3)------------------------------------
	// ft::vector<int> _ve3(_ve2);

	//assign operator--------------------------------------
	// ft::vector<int> _ve4 = _ve2;
	// _ve4 = _ve1;

	//begin andd end and iterators operators-----------------
	// ft::vector<int>::reverse_iterator it;
	// it = _ve2.rbegin(); // it.operator=(v2.begin())'
	// std::cout << *(_ve2.rbegin() + 3) << std::endl;
	// _ve2.reserve(10);

	// ft::vector<int>::iterator it;
	// ft::vector<int>::iterator ite = _ve2.begin() - 1;
	// for(it = _ve2.end(); it != ite; it--)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << _ve2.capacity() << std::endl;


	//assign------------------------------------------------------
	// ft::vector<int> _ve5;
	// _ve5.assign(a1, a1+4);
	// std::cout << _ve5.size() << std::endl;
	// std::cout << _ve5.capacity() << std::endl;
	// std::cout << _ve5.size() << std::endl;

	// ft::vector<int> _ve6;
	// _ve6.assign((size_t)10, 50);

	//push_back---------------------------------------------------------
	// ft::vector<int> _ve7(_ve2);
	// _ve7.push_back(1000000);
	// std::cout << _ve7.size() << std::endl;
	// std::cout << _ve7.capacity() << std::endl;

	//pop_back and clear----------------------------------------------------
	// VE_INT _ve8(_ve2);
	// _ve8.pop_back();
	// std::cout << _ve8.size() << std::endl;
	// std::cout << _ve8.capacity() << std::endl;
	// std::cout << "-------------" << std::endl;

	//resize---------------------------------------------------------
	// VE_INT _ve8(_ve2);

    // _ve8.resize(0, 20);
    // for(size_t i = 0; i < _ve8.size(); i++)
    // {
    //     std::cout << _ve8[i] << std::endl;
    // }
	// std::cout << "-------------" << std::endl;
	// std::cout << _ve8.size() << std::endl;
	// std::cout << _ve8.capacity() << std::endl;

	// for (size_t i = 0; i < _ve8.size(); i++)
	// 	std::cout << _ve8[i] << std::endl;

	//swap---------------------------------------------------------------------
	// int a1[7] = {10, 20, 30, 40, 50, 60, 70};
	// VE_INT _ve2(a1, a1+7);

	// int a2[5] = {100, 200, 300, 400, 500};
	// VE_INT _ve(_ve2);
	// VE_INT _ve1(a2, a2+5);

	// _ve.swap(_ve1);

	// for (size_t i = 0; i < _ve.size(); i++)
	// 	std::cout << _ve[i] << std::endl;
	// std::cout << "-----------------------------" << std::endl;
	// for (size_t i = 0; i < _ve1.size(); i++)
	// 	std::cout << _ve1[i] << std::endl;

	// //erase----------------------------------------------------------------
	// int a1[7] = {10, 20, 30, 40, 50, 60, 70};
    // VE_INT _ve(a1, a1+7);
	// // std::cout << "wtf " << *(_ve.begin(), _ve.begin() + 3) << std::endl;
    // // std::cout << *(_ve.erase(_ve.begin() + 3, _ve.end() - 3)) << std::endl;
	// _ve.erase(_ve.begin() + 3, _ve.end());
    // for (size_t i = 0; i < _ve.size(); i++)
	// 	std::cout << _ve[i] << std::endl;

	//insert-----------------------------------------------------------------
	// VE_INT _ve(5, 10);
	// VE_INT _v1(5, 10);
    // VE_INT _v(600, 500);
    // // _ve.insert(_ve.begin()+ 10, _v.begin(), _v.end());
    // for (size_t i = 0; i < _ve.size(); i++)
	// 	std::cout << _ve[i] << std::endl;
	// for (size_t i = 0; i < _v.size(); i++)
	// 	std::cout << _v[i] << std::endl;
	// if(_v >= _ve)
	// 	puts("jjjjj");
	// else
	// 	puts("hhhhhhhhh");
    return 0;
}


// notes to add
//(2): if the range given is bigger than  the array size

//erase: 	-if a the iterator out of range it gives a 0(undefined behavior)
//			what should i do in this situation

//			-i have a problem in the retun