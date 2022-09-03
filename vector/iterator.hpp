#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <stdexcept>
#include <iterator>

namespace ft{
    template <class T>
    class MyIterator
    {
        public:
            //typedefs
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            typedef ptrdiff_t                           difference_type;
            typedef  std::random_access_iterator_tag    iterator_category;
        
        private:
            pointer _ptr;

        public:
            // default cnstructor
            MyIterator() : _ptr() {}

            MyIterator(pointer cp)
            {
                _ptr = cp;
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
                // std::cout << "Desctructor Called" << std::endl;
            }

            //--------------------------------------------------------------------

            // operators begin
            bool operator==(MyIterator &rhs)
            {
                if (this->_ptr == rhs._ptr)
                    return true;
                else
                    return false;
            }
            bool operator!=(MyIterator &rhs)
            {
                if (this->_ptr != rhs._ptr)
                    return true;
                else
                    return false;
            }
            reference &operator*()
            {
                return *_ptr;
            }
            pointer &operator->()
            {
                return _ptr;
            }
            // started here
            MyIterator &operator++()
            {
                this->_ptr++;
                return (*this);
            }
            MyIterator &operator++(int)
            {
                MyIterator cp(*this);
                ++_ptr;
                return (cp);
            }
            MyIterator &operator--()
            {
                this->_ptr--;
                return (*this);
            }
            MyIterator &operator--(int)
            {
                MyIterator cp(*this);
                --_ptr;
                return (cp);
            }
            MyIterator &operator+(int n)
            {
                MyIterator cp(*this);
                cp += n;
                return cp;
            }
            MyIterator &operator-(int n)
            {
                MyIterator cp(*this);
                cp -= n;
                return cp;
            }
            difference_type operator-(MyIterator &it)
            {
                difference_type diff = this->_ptr - it._ptr;
                return diff;
            }

            // missing n + a and n - a
            // is it working the same way?
            // we'll  see
            
            bool    operator<(MyIterator &it)
            {
                if(this->_ptr < it._ptr)
                    return true;
                else
                    return false;
            }
            bool    operator>(MyIterator &it)
            {
                if(this->_ptr > it._ptr)
                    return true;
                else
                    return false;
            }
            bool    operator<=(MyIterator &it)
            {
                if(this->_ptr <= it._ptr)
                    return true;
                else
                    return false;
            }
            bool    operator>=(MyIterator &it)
            {
                if(this->_ptr >= it._ptr)
                    return true;
                else
                    return false;
            }
            MyIterator operator+=(int n)
            {
                MyIterator cp(*this);
                cp += n;
                return cp;
            }
            MyIterator operator-=(int n)
            {
                MyIterator cp(*this);
                cp -= n;
                return cp;
            }
            reference operator[](int n)
            {
                return _ptr[n];
            }
    };
}
#endif