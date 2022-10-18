#include "./Stack---/stack.hpp"

typedef ft::stack<int> ST_INT;
typedef ft::vector<int> VE_INT;

int main()
{
    //constructor----------------------------------------------------------------------------------------------------------          // deque with 3 elements
    // VE_INT myvector (2,200);        // vector with 2 elements

    // ST_INT first;                    // empty stack

    // ft::stack<int,VE_INT > third;  // empty stack using vector
    // ft::stack<int,VE_INT > fourth (myvector);

    // std::cout << "size of first: " << first.size() << '\n';
    // std::cout << "size of third: " << third.size() << '\n';
    // std::cout << "size of fourth: " << fourth.size() << '\n';

    // empty---------------------------------------------------------------------------------------------------------------
    // ST_INT  mystack;
    // int sum (0);

    // for (int i=1;i<=10;i++) 
    //     mystack.push(i);

    // while (!mystack.empty())
    // {
    //     sum += mystack.top();
    //     mystack.pop();
    // }

    // std::cout << "total: " << sum << '\n';

    //size------------------------------------------------------------------------------------------------------------------
    // ST_INT myints;
    // std::cout << "0. size: " << myints.size() << '\n';

    // for (int i=0; i<5; i++) 
    //     myints.push(i);
    // std::cout << "1. size: " << myints.size() << '\n';

    // myints.pop();
    // std::cout << "2. size: " << myints.size() << '\n';

    //top-------------------------------------------------------------------------------------------------------------------
    // ST_INT mystack;

    // mystack.push(10);
    // mystack.push(20);

    // mystack.top() -= 5;

    // std::cout << "mystack.top() is now " << mystack.top() << '\n';

    //push-----------------------------------------------------------------------------------------------------------------
    // ST_INT mystack;

    // for (int i=0; i<5; ++i) mystack.push(i);

    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';


    //pop-----------------------------------------------------------------------------------------------------------------
    // ST_INT mystack;

    // for (int i=0; i<5; ++i) mystack.push(i);

    // std::cout << "Popping out elements...";
    // while (!mystack.empty())
    // {
    //     std::cout << ' ' << mystack.top();
    //     mystack.pop();
    // }
    // std::cout << '\n';

    //operators----------------------------------------------------------------------------------------------------------
    // ST_INT mystack;
    // ST_INT stack;

    // for (int i=0; i<5; ++i) mystack.push(i);
    // for (int i=0; i<10; ++i) stack.push(i);

    // if(stack != mystack)
    //     puts("true");
    // else
    //     puts("false");
    return 0;
}