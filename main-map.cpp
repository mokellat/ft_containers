#include "map/map.hpp"

int main()
{
    //int int
    ft::map<int, int> m;

    //insert
    m.insert(ft::pair<int, int>(1, 10));
    m.insert(ft::pair<int, int>(2, 20));
    m.insert(ft::pair<int, int>(2, 20));
    m.insert(ft::pair<int, int>(3, 30));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    return 0;
}