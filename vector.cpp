#include <iostream>
#include <vector>

typedef std::vector<int> VE_INT;

int main()
{
    // size_t n = 5;
    // std::vector<int> _ve1(n, 15);

    // std::vector<int> _ve(_ve1.begin(), _ve1.end());


    // std::vector<int> _ve3(_ve1);

    // int a1[5] = {10, 20, 30, 40, 50};

    // std::vector<int> _ve2(a1, a1+5);

    // ptrdiff_t diff = std::distance(a1+4, a1);
    // std::cout << diff << std::endl;

    // std::vector<int> _ve4;
    // _ve4 = _ve1;

    // std::vector<int>::iterator it;
    // it = _ve4.begin();
    // std::cout << "hh: " << _ve2.size() << std::endl;
    // std::vector<int>::reverse_iterator it;
	// it = _ve2.begin(); // it.operator=(v2.begin())'
    // _ve2.reserve(10);
    // std::vector<int>::iterator it;
	// std::vector<int>::iterator ite = _ve2.begin() - 1;
	// std::cout << _ve2.capacity() << std::endl;
    // for(it = _ve2.end(); it != ite; it--)
	// {
	// 	std::cout << *it << std::endl;
	// }

    // std::vector<int> _ve7(_ve2);

	// _ve7.push_back(1000000);
	// std::cout << _ve7.size() << std::endl;
	// std::cout << _ve7.capacity() << std::endl;

    // VE_INT _ve8(_ve2);
	// // _ve8.clear();
	// // std::cout << _ve8[0] << std::endl;
	// // std::cout << _ve8.capacity() << std::endl;

    // _ve8.resize(10, 20);
    // for(size_t i = 0; i < _ve8.size(); i++)
    // {
    //     std::cout << _ve8[i] << std::endl;
    // }


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

    // int a1[7] = {10, 20, 30, 40, 50, 60, 70};
    // VE_INT _ve(a1, a1+7);
    // // std::cout << "wtf " << *(_ve.begin(), _ve.begin() + 3) << std::endl;
    // std::cout << "here " << *_ve.erase(_ve.begin() + 3, _ve.end()) << std::endl;
    // for (size_t i = 0; i < _ve.size(); i++)
	// 	std::cout << _ve[i] << std::endl;

    VE_INT _ve(5, 10);
    _ve.insert(_ve.begin()+ 10, 70);
    for (size_t i = 0; i < _ve.size(); i++)
		std::cout << _ve[i] << std::endl;
}