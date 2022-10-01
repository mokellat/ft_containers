#pragma once

// #include "AVL.hpp"
#include <functional>
#include <utility>

namespace ft
{
// Node    *MostLeft(Node *node)
// {
//     if(node != NULL)
//     {
//         Node *iter = node;

//         while (iter->left != NULL)
//             iter = iter->_left;
//         return iter
//     }
//     else
//         return NULL:
// }

// Node    *MostRight(Node *node)
// {
//     if(node != NULL)
//     {
//         Node *iter = node;

//         while (iter->right != NULL)
//             iter = iter->right;
//         return iter
//     }
//     else
//         return NULL;
// }

// template <class T> 
// struct equal_to : binary_function <T,T,bool> {
//   bool operator() (const T& x, const T& y) const {return x==y;}
// };

    template <class T1, class T2>
    struct pair // all members all public by default
    {

        //typedef
        typedef T1  first_type;
        typedef T2  second_type;

        private:
            first_type  first;
            second_type second;

        pair() {}

        template<class U, class V> 
        pair (const pair<U,V>& pr) 
        {
            first = pr.first;
            second = pr.second;
        }

        pair (const first_type& a, const second_type& b)
        {
            first = a;
            second = b;
        }

        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return *this;
        }

    };

    //pair non member functions
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }

    //std::make_pair-----------------------------------------------
    // template <class T1, class T2>
    // pair<T1,T2> make_pair (T1 x, T2 y)
    // {
    //     return (pair<T1,T2>(x,y));
    // };

    //std::make_pair-----------------------------------------------
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y));
    };
}