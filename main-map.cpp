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
    //int int
    ft::map<int, int>   m;
    // ft::pair<ft::map<int, int>::iterator, bool> it;

    // //insert--------------------------------------------------------------------
    // it = m.insert(ft::pair<int, int>(1, 10));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);
    // it = m.insert(ft::pair<int, int>(2, 20));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);
    // it = m.insert(ft::pair<int, int>(3, 30));
    // myprint(it.first->first);
    // myprint(it.first->second);
    // myprint(it.second);
    m.insert(ft::pair<int, int>(2, 20));
    m.insert(ft::pair<int, int>(9, 20));
    m.insert(ft::pair<int, int>(12, 30));
    m.insert(ft::pair<int, int>(33, 35));
    m.insert(ft::pair<int, int>(16, 40));
    m.insert(ft::pair<int, int>(10, 50));
    m.insert(ft::pair<int, int>(0, 50));
    m.insert(ft::pair<int, int>(-1, 50));
    // m.insert(ft::pair<int, int>(20, 50));
    // m.insert(ft::pair<int, int>(1, 50));
    // m.insert(ft::pair<int, int>(100, 50));
    // m.insert(ft::pair<int, int>(101, 50));
    // m.insert(ft::pair<int, int>(102, 50));
    // m.insert(ft::pair<int, int>(90, 50));
    // m.insert(ft::pair<int, int>(80, 50));
    // m.insert(ft::pair<int, int>(84, 50));
    // m.insert(ft::pair<int, int>(94, 50));
    // m.insert(ft::pair<int, int>(3344, 50));
    // m.insert(ft::pair<int, int>(440, 50));
    // m.insert(ft::pair<int, int>(4, 50));        // causes a segv when building with iterators
    // m.insert(ft::pair<int, int>(-888884, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(76464647644, 50));
    // m.insert(ft::pair<int, int>(776344, 50));
    // m.insert(ft::pair<int, int>(-773, 50));
    // m.insert(ft::pair<int, int>(10000000000, 50));
    // m.insert(ft::pair<int, int>(8844, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(77635354, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));
    // m.insert(ft::pair<int, int>(4, 50));

    m.tree_print();
    // myprint(m.size());
    // m.print();
    // m.root();
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // printTree(m, "", true);

    //construct using iterator--------------------------------------------------------
    // myprint("--------------------------------");
    // ft::map<int, int> m2(m.begin(), m.end());
    // m2.tree_print();

    // myprint("--------------------------------");

    // ft::map<int, int>::iterator it = m.end();
    // for(it--; it != m.begin(); it--)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }
    
    // myprint("--------------------------------");

    // ft::map<int, int>::iterator ite = m2.end();
    // for(ite--; ite != m2.begin(); ite--)
    // {
    //     // puts("hree");
    //     myprint(ite->first);
    //     // myprint(it->second);
    // }

    //construct using another map--------------------------------------------------------------
    ft::map<int, int> m3(m);
    // myprint(m.size());
    myprint(m3.size());

    // m3.tree_print();

    // construct using operator=------------------------------------------------------------------------------
    // ft::map<int, int> m4 = m;

    // [] insert using [] operator---------------------------------------------------------------
    // m.insert(ft::pair<int, int>(1, 10));
    // m[10] = 20;
    // m[5] = 20;
    // m[20] = 20;
    // m[7] = 20;
    // m[4] = 20;
    // m[8] = 20;
    // m[0] = 20;
    // m[-1] = 20;
    // m[2] = 30;
    // m[13] = 10;
    // m[30] = 10;
    // m[30] = 10;
    // // m.tree_print();
    // m[-30] = 10;
    // m[4] = 30;
    // m[6] = 60;
    // m[-2] = 60;
    // m.tree_print();
    
    // m[-2] = 30;
    // m.print();

    //iterators-----------------------------------------------------------------------------------------------
    // ft::map<int, int>::iterator it = m.end();
    // it--;

    // myprint((it->first));
    // for(it--; it != m.begin(); it--)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }
        // myprint(it->first);

    // ft::map<int, int>::const_iterator it;
    // ft::map<int, int>::const_iterator ite = m.end();

    // for(it = m.begin(); it != ite; ++it)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }
    // it++;
    // myprint(it->first);
    // myprint(it->second);

    //reverse_iterators-------------------------------------------------------------------------------
    // ft::map<int, int>::reverse_iterator rit;
    // for(rit = m.rbegin(); rit !=m.rend(); ++rit)
    // {
    //     // puts("hree");
    //     myprint(rit->first);
    //     // myprint(it->second);
    // }
    // myprint(rit->first);

    // empty and size and max size------------------------------------------------------------------------------------------
    // ft::map<int, int> m5;

    // myprint(m5.size());
    // myprint(m.size());

    // myprint(m5.empty());
    // myprint(m.empty());

    // myprint(m5.max_size());
    // myprint(m.max_size());

    // erase------------------------------------------------------------------------------------------
    // m.erase(3);
    // ft::map<int, int>::iterator it = m.begin();
    // for(; it != m.end(); it++)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }
    // m.tree_print();
    // m.erase(30);
    // m.erase(10);
    // m.erase(17);
    // m.erase(100);
    // m.erase(94);
    // m.erase(97);
    // m.tree_print();
    // it = m.begin();
    // ft::map<int, int>::iterator it = m.begin();
    // for(; it != m.end(); it++)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }


    //SWAP--------------------------------------------------------------------------------------------
    // ft::map<int, int> m6;
    // m6.insert(ft::pair<int, int>(1, 20));
    // m6.insert(ft::pair<int, int>(5, 30));
    // m6.insert(ft::pair<int, int>(3, 35));
    // m6.insert(ft::pair<int, int>(2, 40));
    // m6.insert(ft::pair<int, int>(10, 40));

    // m6.swap(m);

    // myprint("-----------------------------------");
    // m6.tree_print();
    // myprint("-----------------------------------");
    // m.tree_print();
    // myprint("-----------------------------------");

    // // //m here
    // ft::map<int, int>::iterator it = m.begin();
    // for(; it != m.end(); it++)
    // {
    //     // puts("hree");
    //     myprint(it->first);
    //     // myprint(it->second);
    // }

    //m6 here
    // myprint("*****************************");
    // ft::map<int, int>::iterator it2 = m6.begin();
    // for(; it2 != m6.end(); it2++)
    // {
    //     // puts("hree");
    //     myprint(it2->first);
    //     // myprint(it->second);
    // }

    // lower_bound and upper_bound--------------------------------------------------------------------
    // ft::map<int, int>::iterator it = m.lower_bound(30);
    // ft::map<int, int>::iterator ite = m.upper_bound(30);
    // myprint(it->first);
    // myprint(ite->first);


    //clear---------------------------------------------------------------------------------------------
    // m.tree_print();
    // // m.clear();
    // myprint("------------------------------------------------------------------");
    // m.tree_print();
    //char int
    // ft::map<char, int> m1;
    // m1.insert(ft::pair<char, int>('a', 10));
    // m1.insert(ft::pair<char, int>('x', 20));
    // m1.insert(ft::pair<char, int>('j', 20));
    // m1.insert(ft::pair<char, int>('k', 30));
    // m1.insert(ft::pair<char, int>('l', 35));
    // m1.tree_print();
    // return 0;
}