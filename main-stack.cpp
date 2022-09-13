#include "./Stack---/stack.hpp"

typedef ft::stack<int> ST_INT;

int main()
{
    ST_INT s;

    s.push(10);
    s.push(20);
    while(!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}