#pragma once

#include <iostream>
#include <iterator>
#include"map/node_helper.hpp"


namespace ft
{
    template<class T>
    class mapIterator
    {
        public:
            //typedefs
            typedef typename std::bidirectional_iterator_tag	iterator_category;
            typedef typename T::first                           value_type;
            typedef Node<value_type>                            node_type;
            typedef T*                                          pointer;
		    typedef T&	                                        reference;


        private:
            node_type *_node;

        public:
            mapIterator() : _node(){}

            mapIterator(node_type *node) : _node(node){}

            mapIterator(mapIterator &it)
            {
                _node = it._node;
            }

            ~mapIterator(){}        

            mapIterator &operator=(mapIterator &rhs)
            {
                _node = rhs._node;
                return *this;
            }

            bool &operator==(mapIterator &rhs)
            {
                return (_node == rhs.node);
            }

            bool &operator!=(mapIterator &rhs)
            {
                return (node != rhs._node);
            }

            reference	operator*() 
            {
                //donno what to do here
                return *(_node->pair);
            }

		    pointer	operator->()
            {
                //donno what to do here
                return _node->pair;
            }

            mapIterator &operator++()
            {
                // for later
                if(_node == NULL)
                {
                    
                }
                return *this;
            }

            mapIterator &operator++(int)
            {
                mapIterator it(*this);
                (this)++;
                return it;
            }

             mapIterator &operator--()
            {
                // for later
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
