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
            typedef T*                                          pointer;
		    typedef T&	                                        reference;


        private:
            node_type   *_node;
            node_type   *_check;

        private:
            node_type    *MostLeft(node_type *node)
            {
                if(node != NULL)
                {
                    node_type *iter = node;

                    while (iter->left != NULL)
                        iter = iter->left;
                    return iter;
                }
                else
                    return NULL;
            }

            node_type    *MostRight(node_type *node)
            {
                if(node != NULL)
                {
                    node_type *iter = node;

                    while (iter->right != NULL)
                        iter = iter->right;
                    return iter;
                }
                else
                    return NULL;
            }

        public:
            mapIterator() : _node(){}

            mapIterator(node_type *node) : _node(node){}

            mapIterator(const node_type *node)
            {
                (const node_type) _node = node;
            }

            mapIterator(mapIterator const &it)
            {
                _node = it._node;
            }

            mapIterator(node_type *node, node_type *check) : _node(node), _check(check)
            {
                
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

            mapIterator operator--()
            {
                // for later
                if(_node == NULL)
                {
                    node_type *temp;

                    temp = MostRight(_check);
                    _node = temp;
                    _check = NULL;
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
