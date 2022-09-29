#pragma once

#include "AVL.hpp"
#include <functional>


Node    *MostLeft(Node *node)
{
    if(node != NULL)
    {
        Node *iter = node;

        while (iter->left != NULL)
            iter = iter->_left;
        return iter
    }
    else
        return NULL:
}

Node    *MostRight(Node *node)
{
    if(node != NULL)
    {
        Node *iter = node;

        while (iter->right != NULL)
            iter = iter->right;
        return iter
    }
    else
        return NULL;
}

// template <class T> 
// struct equal_to : binary_function <T,T,bool> {
//   bool operator() (const T& x, const T& y) const {return x==y;}
// };