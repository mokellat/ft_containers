#include "./vector/vector.hpp"

int main()
{
    //default-----------------------------------
    ft::vector<int> _ve;

    //(1)-----------------------------------
    size_t n = 5;
    ft::vector<int> _ve1(n, 10);

    // for (size_t i = 0; i < _ve1.size(); i++)
    //     std::cout << _ve1[i] << std::endl;

    // (2)-----------------------------------
		ft::vector<int> _ve2(_ve1.begin(), _ve1.end());

    return 0;
}