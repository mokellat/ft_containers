#pragma once

#include "AVL.hpp"

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
        return NULL:
}