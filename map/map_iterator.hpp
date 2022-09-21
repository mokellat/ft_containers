#pragma once

#include <iostream>
#include <iterator>


namespace ft
{
    template<class T>
    class mapIterator
    {
        public:
            //typedefs
            typedef T                   value_type;
            typedef Node<value_type>    node_type;
            typedef typename std::bidirectional_iterator_tag	iterator_category;

        private:
            Node<value_type> *_node;

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
                return *(_node->value); 
            }

		    pointer	operator->()
            {
                return _node->value; 
            }

            mapIterator &operator++()
            {
                // for later
            }

            mapIterator &operator++(int)
            {
                mapIterator it(*this);
                operator++();
                return it;
            }

             mapIterator &operator--()
            {
                // for later
            }

            mapIterator &operator--(int)
            {
                mapIterator it(*this);
                operator--();
                return it;
            }
    };
}
