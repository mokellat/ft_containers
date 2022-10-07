#include "map/map.hpp"
#define myprint(X) std::cout << X << std::endl 


// void printTree(Node *root, std::string indent, bool last) {
//   if (root != nullptr) {
//     cout << indent;
//     if (last) {
//       cout << "R----";
//       indent += "   ";
//     } else {
//       cout << "L----";
//       indent += "|  ";
//     }
//     cout << root->key << endl;
//     printTree(root->left, indent, false);
//     printTree(root->right, indent, true);
//   }
// }

int main()
{
    // #define std::cout << y << std::endl myprint(y)
    //int int
    ft::map<int, int> m;
    // ft::pair<ft::map<int, int>::iterator, bool> it;

    // //insert
    // it = m.insert(ft::pair<int, int>(1, 10));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);

    // myprint("----------------------------");

    // it = m.insert(ft::pair<int, int>(2, 20));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);

    // myprint("----------------------------");


    // it = m.insert(ft::pair<int, int>(3, 30));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);


    // m.insert(ft::pair<int, int>(2, 20));
    // m.insert(ft::pair<int, int>(2, 20));
    // m.insert(ft::pair<int, int>(3, 30));
    // m.insert(ft::pair<int, int>(0, 35));
    // m.insert(ft::pair<int, int>(4, 40));
    // m.insert(ft::pair<int, int>(5, 50));
    
    // m.print();
    // m.root();
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // printTree(m, "", true);

    //construct using iterator
    // ft::map<int, int> m2(m.begin(), m.end());

    // [] insert using [] operator
    // m.insert(ft::pair<int, int>(1, 10));
    m[9] = 20;
    m[12] = 20;
    m[33] = 20;
    m[16] = 20;
    m[10] = 20;
    m[0] = 20;
    m[-1] = 20;
    m[20] = 30;
    m[1] = 10;
    m[4] = 30;
    // m.print();

    //iterators
    // ft::map<int, int>::iterator it = m.end();
    // for(it--; it != m.begin(); it--)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }
        // myprint(it->first);

    ft::map<int, int>::iterator it;
    for(it = m.begin(); it!=m.end(); it++)
    {
        // puts("hree");
        myprint(it->first);
        // myprint(it->second);
    }
    // it++;
    // myprint(it->first);
    // myprint(it->second);

    // erase
    // m.erase(3);

    // lower_bound and upper_bound
    // ft::map<int, int>::iterator it = m.lower_bound(5);
    // ft::map<int, int>::iterator ite = m.upper_bound(5);

    //SWAP

    //char int
    // ft::map<char, int> m1;
    // m1.insert(ft::pair<char, int>('1', 10));
    // m1.insert(ft::pair<char, int>('2', 20));
    // m1.insert(ft::pair<char, int>('2', 20));
    // m1.insert(ft::pair<char, int>('3', 30));
    // m1.insert(ft::pair<char, int>('0', 35));

    return 0;
}