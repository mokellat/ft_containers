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
            // typedef typename T::first                           value_type;
            typedef Node<T>                                     node_type;
            typedef T*                                          pointer;
		    typedef T&	                                        reference;


        private:
            node_type   *_node;

        public:
            mapIterator() : _node(){}

            mapIterator(node_type *node) : _node(node){}

            mapIterator(mapIterator const &it)
            {
                _node = it._node;
            }

            ~mapIterator(){}        

            mapIterator &operator=(mapIterator const &rhs)
            {
                _node = rhs._node;
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
                if(_node->right != NULL)
                {
                    _node = _node->right;
                    while (_node->right != NULL)
                        _node = _node->right;
                }
                else
                {
                    node_type    *temp_par = _node->parent;

                    while (_node == temp_par->right)
                    {
                       _node = temp_par;
                       temp_par = _node->parent;
                    }
                    if(_node->right != temp_par)
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

            mapIterator operator--()
            {
                // for later
                if(_node->left != NULL)
                {
                    _node = _node->left;
                    while (_node->left != NULL)
                        _node = _node->left;
                }
                else
                {
                    node_type   *temp_par = _node->parent;

                    while (_node == temp_par->left)
                    {
                       _node = temp_par;
                       temp_par = _node->parent;
                    }
                    if(_node->left != temp_par)
                        _node = temp_par;
                }
                return *this;
            }

            mapIterator &operator--(int)
            {
                mapIterator it(*this);
                (*this)--;
                return it;
            }
    };
}
