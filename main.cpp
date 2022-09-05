#include "./vector/vector.hpp"

int main()
{
    //default-----------------------------------
    // ft::vector<int> _ve;

    //(1)-----------------------------------
    size_t n = 5;
    ft::vector<int> _ve1(n, 10);

    // for (size_t i = 0; i < _ve1.size(); i++)
    //     std::cout << _ve1[i] << std::endl;

    // (2)-----------------------------------
	int a1[5] = {10, 20, 30, 40, 50};

	ft::vector<int> _ve2(a1, a1+5);

	//(3)------------------------------------
	ft::vector<int> _ve3(_ve2);

	//assign operator--------------------------------------
	// ft::vector<int> _ve4 = _ve2;
	// _ve4 = _ve1;

	//begin andd end
	// ft::vector<int>::reverse_iterator it;
	// it = _ve2.rbegin(); // it.operator=(v2.begin())'
	std::cout << *(_ve2.end() - 1) << std::endl;
	// for (size_t i = 0; i < _ve2.size(); i++)
	// 	std::cout << _ve2[i] << std::endl;
    return 0;
}


// int main()
// {
// 	ft::MyIterator<int> it(NULL);
// }

// notes to add

//(2): if the range given is bigger than  the array size