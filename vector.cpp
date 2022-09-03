#include <iostream>
#include <vector>


int main()
{
    size_t n = 5;
    std::vector<int> _ve1(n, 15);

    std::vector<int> _ve(_ve1.begin(), _ve1.end());


    std::vector<int> _ve3(_ve1);

    int a1[5] = {10, 20, 30, 40, 50};

    std::vector<int> _ve2(a1, a1);

    // ptrdiff_t diff = std::distance(a1+4, a1);
    // std::cout << diff << std::endl;

    std::vector<int> _ve4;
    _ve4 = _ve1;

    std::vector<int>::iterator it;
    it = _ve4.begin();
    // std::cout << "value " <<*it << std::endl;
    for (size_t i = 0; i < _ve2.size(); i++)
        std::cout << _ve2[i] << std::endl;
}