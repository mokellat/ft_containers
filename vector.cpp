#include <iostream>
#include <vector>


int main()
{
    size_t n = 5;
    std::vector<int> _ve1(n, 15);

    std::vector<int> _ve(_ve1.begin(), _ve1.end());

    for (size_t i = 0; i < _ve.size(); i++)
        std::cout << _ve[i] << std::endl;
}