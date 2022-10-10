#pragma once

#include <iostream>
#include <iterator>
#include "AVL.hpp"
// #include "map/node_helper.hpp"

namespace ft
{
    template<class T>
    class mapIterator
    {
        public:
            //typedefs
            typedef typename std::bidirectional_iterator_tag	iterator_category;
            typedef T                                           value_type;
            typedef ptrdiff_t	                                difference_type;
            typedef Node<T>                                     node_type;
            typedef Node<const T>                               const_node_type;
            typedef T*                                          pointer;
		    typedef T&	                                        reference;



        private:
            node_type   *_node;
            node_type   *_check;

            // node_type    *MostLeft(node_type *node)
            // {
            //     if(node != NULL)
            //     {
            //         node_type *iter = node;

            //         while (iter->left != NULL)
            //             iter = iter->left;
            //         return iter;
            //     }
            //     else
            //         return NULL;
            // }

            // node_type    *MostRight(node_type *node)
            // {
            //     // if(node != NULL)
            //     // {
            //     //     node_type *iter = node;

            //     //     while (iter->right != NULL)
            //     //         iter = iter->right;
            //     //     return iter;
            //     // }
            //     // else
            //     //     return NULL;
            //     if(node == NULL)
            //         return node;
            //     if(node->right == NULL)
            //         return node;
            //     return MostRight(node->right);
            // }

        public:
            mapIterator() : _node(), _check() {}

            mapIterator(node_type *node) : _node(node), _check(node) {}

            // mapIterator(const node_type *node)
            // {
            //     (const node_type) _node = node;
            // }

            mapIterator(mapIterator const &it)
            {
                _node = it._node;
                _check = it._check;
            }


            mapIterator(node_type *node, node_type *check) : _node(node), _check(check)
            {
                
            }

            // operator mapIterator<const T>()
            // {
            //     const_node_type *node = (const_node_type *)_node;
            //     const_node_type *check = (const_node_type *)_check;
            //     mapIterator<const T> tmp(node, check);
            //     return tmp;
            // }
            
            ~mapIterator(){}        

            mapIterator &operator=(mapIterator const &rhs)
            {
                _node = rhs._node;
                _check = rhs._check;
                return *this;
            }

            bool operator==(mapIterator const &rhs) const
            {
                return (_node == rhs._node);
            }

            bool operator!=(mapIterator const &rhs) const
            {
                return (_node != rhs._node);
            }

            reference	operator*() const
            {
                //donno what to do here
                // if(!_node)
                //     puts("12");
                return *_node->key;
            }

		    pointer	operator->()
            {
                //donno what to do here
                return _node->key;
            }

            mapIterator &operator++()
            {
                // i ll explain what i did here for later
                if (_node && _node == _node->MostRight(_check))
                {
                    _node = NULL;
                    return *this;
                }

                if(_node->right != NULL)
                {
                    // puts("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
                    _node = _node->right;
                    while (_node->left != NULL)
                        _node = _node->left;
                }
                else
                {
                    node_type    *temp_par = _node->parent;

                    while (temp_par && _node == temp_par->right)
                    {
                       _node = temp_par;
                       temp_par = _node->parent;
                    }
                    // if(_node->right != temp_par)
                    _node = temp_par;
                }
                return *this;
            }

            mapIterator operator++(int)
            {
                mapIterator it(*this);
                ++(*this);
                return it;
            }

            mapIterator &operator--()
            {
                // puts("wtf");
                // for later
                if(_node != NULL)
                {
                    if(_node && _node == _node->MostLeft(_check))
                    {
                        _node = NULL;
                        return *this;
                    }
                    if(_node->left != NULL)
                    {
                        _node = _node->left;
                        while (_node->right != NULL)
                            _node = _node->right;
                    }
                    else
                    {
                        node_type   *temp_par = _node->parent;

                        while (temp_par && _node == temp_par->left)
                        {
                            _node = temp_par;
                            temp_par = temp_par->parent;
                        }
                        // if(_node->left != temp_par)
                        _node = temp_par;
                    }
                }
                else
                {
                    // puts("1111111111111111111111111111");
                    _node = _node->MostRight(_check);
                }
                return *this;
            }

            mapIterator operator--(int)
            {
                mapIterator it(*this);
                --(*this);
                return it;
            }
    };
}
