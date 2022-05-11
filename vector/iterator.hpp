#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "library.hpp"

template <class T>
class MyIterator
{
    public:
        //typedefs
        typedef T   value_type;
        typedef T*  pointer;
        typedef T&  reference;
    
    private:
        pointer _ptr;

    public:
        // default constructor
        MyIterator(pointer cp)
        {
            _ptr = abc;
        }
        // copy constructor
        MyIterator(MyIterator &cp)
        {
            this->_ptr = cp._ptr;
        }
        // assignment overload
        MyIterator &operator=(MyIterator &rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this); //forget what this do
        }
        // destructor
        ~MyIterator()
        {
            std::cout << "Desctructor Called" << std::endl;
        }

        // operators begin
        bool &operator==(MyIterator &rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this); //forget what this do
        }
};
#endif