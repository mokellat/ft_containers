#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <cmath>

#define myprint(Y) std::cout << Y << std::endl

namespace ft
{

    // #include "iterator.hpp"
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;

            // iterators
            typedef MyIterator<value_type>                          iterator;
            typedef MyIterator<const value_type>                    const_iterator;

            // reverse iterator
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

        private:
            pointer                                                 _ptr;
            allocator_type                                          _alloc_copy;
            size_type                                               _size;
            size_type                                               _capacity;
        
        public:

            //member fuctions---------------------------------

            //Constructors
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                //initialize the variables
                _size = 0;
                _capacity = 0;
                this->_alloc_copy = alloc;
            }
            //(1)
            explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type())
            {
                // std::cout << "im heeeeeeeeeeeere" << std::endl;
                this->_alloc_copy = alloc;
                _size = n;
                _capacity = n;
                _ptr = _alloc_copy.allocate(n);
                for(size_type i = 0; i < n; i++)
                    _alloc_copy.construct(&_ptr[i], val);
            }
            //(2)
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(), typename enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type = NULL)
            {
                this->_alloc_copy = alloc;
                difference_type diff = std::distance(first, last);
                if(diff < 0)
                    throw std::length_error("constructor: range error");
                _size = diff;
                _capacity = diff;
                //what if the difference is < 0
                if(diff > 0)
                {
                    _ptr = _alloc_copy.allocate(diff);
                    for(int i = 0; i < diff; i++)
                        _alloc_copy.construct(&_ptr[i], *first++);
                }
            }
            //(3)
            vector (const vector& x)
            {
                // std::cout << "im heeeeeeeeeeeere" << std::endl;
                this->_ptr = NULL;
                this->_size = 0;
                this->_capacity = 0;
                this->_alloc_copy = x._alloc_copy;
                *this = x;
            }

            //Destructor
            ~vector()
            {
                // std::cout << "size " << this->_size << std::endl;
                // std::cout << "size " << this->_capacity << std::endl;
                if(_size > 0)
                {
                    // std::cout << "my job done inside" << std::endl;
                    for(size_type i = 0; i < this->_size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                    _alloc_copy.deallocate(_ptr, this->_capacity);
                }
                // std::cout << "my job done outside" << std::endl;
            }
            
            //assignement overload
            vector& operator=(const vector& x)
            {
                // deallocate and destroy whats in the container then copy
                // std::cout << this->_capacity << std::endl;
                if(_ptr)
                {
                    for(size_type i = 0; i < this->_size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                    if(this->_capacity > 0)
                        _alloc_copy.deallocate(_ptr, this->_capacity);
                }
                this->_alloc_copy = x._alloc_copy;
                if(x._size > 0)
                    _ptr = _alloc_copy.allocate(x._size);
                for(size_type i = 0; i < x._size; i++)
                    _alloc_copy.construct(&_ptr[i], x._ptr[i]);
                this->_size = x._size;
                this->_capacity = x._capacity;
                // *this = x;
                return *this;
            }

            //iterators------------------------------------
            iterator begin()
            {
                return iterator(_ptr);
            }

            const_iterator begin() const
            {
                return const_iterator(_ptr);
            }

            iterator end()
            {
                return iterator(&_ptr[_size]);
            }
            const_iterator end() const
            {
                return const_iterator(&_ptr[_size]);
            }

            reverse_iterator rbegin()
            {
                // std::cout << "hhh" << std::endl;
                return reverse_iterator(_ptr + _size);
            }

            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(_ptr + _size);
            }

            reverse_iterator rend()
            {
                return reverse_iterator(_ptr);
            }

            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(_ptr);
            }
            
            //Capacity--------------------------------------------
            size_type size() const
            {
                return this->_size;
            }

            size_type max_size() const
            {
                return _alloc_copy.max_size();
            }

            void resize (size_type n, value_type val = value_type())
            {
                pointer temp;
                // If n is smaller than the current container size,
                // the content is reduced to its first n elements.
                if(n < _size)
                {
                    // If n is smaller than the current container size, the content is reduced 
                    // to its first n elements
                    for(size_type i = n; i < this->_size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                    _size = n;
                }
                else if(n > _size)
                {
                    // If n is greater than the current container size, the content is 
                    // expanded by inserting at the end as many elements as needed to reach a size of n.
                    for(size_type i = _size; i < n; i++)
                        push_back(val);
                    if(n > _capacity)
                    {
                        // If n is also greater than the current container capacity, an automatic 
                        // reallocation of the allocated storage space takes place.

                        //deallocation
                        temp = _alloc_copy.allocate(_size);
                        for(size_type i = 0; i < this->_size; i++)
                        {
                            _alloc_copy.destroy(&_ptr[i]);
                            _alloc_copy.construct(&temp[i], _ptr[i]);
                        }
                        _alloc_copy.deallocate(_ptr, this->_capacity);

                        //reallocating and constructing
                        _ptr = _alloc_copy.allocate(n);
                        for(size_type i = 0; i < _size; i++)
                            _alloc_copy.construct(&_ptr[i], temp[i]);
                        for(size_type i = _size; i < n; i++)
                            _alloc_copy.construct(&_ptr[i], val);
                        _capacity = n;
                    }
                    _size = n;
                }
            }

            size_type capacity() const
            {
                return this->_capacity;
            }

            bool empty() const
            {
                if(this->_size != 0)
                    return false;
                else
                    return true;
            }

            void reserve (size_type n)
            {
                // Requests that the vector capacity be at least enough to contain n elements.
                if(n > max_size())
                    throw std::length_error("Lenght Error : Max size execeded");
                if(n > this->_capacity)
                {
                    size_type   i;
                    pointer     temp;

                    // If n is greater than the current vector capacity, the function 
                    // causes the container to reallocate its storage increasing its capacity to n (or greater).
                    this->_capacity = n;
                    temp = _alloc_copy.allocate(n);
                    for(i = 0; i < this->_size; i++)
                    {
                        _alloc_copy.construct(&temp[i], _ptr[i]);
                        _alloc_copy.destroy(&_ptr[i]);
                    }
                    if(_size > 0)
                        _alloc_copy.deallocate(_ptr, this->_capacity);
                    // reallocate now
                    _ptr = temp;
                }
            }

            //Element Access--------------------------------------------
            reference operator[] (size_type n)
            {
                return this->_ptr[n];
            }

            const_reference operator[] (size_type n) const
            {
                return this->_ptr[n];
            }

            reference at (size_type n)
            {
                if(n >= 0 && n < this->_size)
                    return this->_ptr[n];
                else
                    throw std::out_of_range("Out of Range Error: 'at' function");
            }

            const_reference at (size_type n) const
            {
                if(n >= 0 && n < this->_size)
                    return this->_ptr[n];
                else
                    throw std::out_of_range("Out of Range Error: 'at' function");
            }

            reference front()
            {
                return this->_ptr[0];
            }   
            const_reference front() const
            {
                return this->_ptr[0];
            }

            reference back()
            {
                return this->_ptr[_size - 1];
            }
            const_reference back() const
            {
                return this->_ptr[_size - 1];
            }

            //Modifiers------------------------------------------------------
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename enable_if<!(is_integral<InputIterator>::value), int>::type = 0)
            {
                // In the range version (1), the new contents are elements constructed from 
                // each of the elements in the range between first and last, in the same order.
                if(_ptr)
                {
                    for(size_type i = 0; i < _size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                }
                difference_type diff = std::distance(first, last);
                if((size_type)diff > this->_capacity)
                {
                    _alloc_copy.deallocate(_ptr, this->_size);
                    this->_capacity = diff;
                    _ptr = _alloc_copy.allocate(this->_capacity);
                }
                this->_size = diff;
                for(difference_type i = 0; i < diff; i++)
                    _alloc_copy.construct(&_ptr[i], *first++);
            }

            void assign (size_type n, const value_type& val)
            {
                size_type i;

                // In the fill version (2), the new contents are n elements, 
                // each initialized to a copy of val.
                if(_ptr)
                {
                    for(i = 0; i < _size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                }
                if(n > this->_capacity)
                {
                    if(_size != 0)
                        _alloc_copy.deallocate(_ptr, this->_size);
                    this->_capacity = n;
                    _ptr = _alloc_copy.allocate(this->_capacity);
                }
                this->_size = n;
                for(i = 0; i < n; i++)
                    _alloc_copy.construct(&_ptr[i], val);
            }

            void push_back (const value_type& val)
            {
                pointer temp;

                if(this->_size + 1 > this->_capacity)
                {
                    this->_capacity *= 2;
                    temp = _alloc_copy.allocate(this->_capacity);
                    for(size_type i = 0; i < this->_size; i++)
                    {
                        _alloc_copy.construct(&temp[i], _ptr[i]);
                        _alloc_copy.destroy(&_ptr[i]);
                    }
                    if(_size == 0)
                    {
                        _alloc_copy.deallocate(temp, _capacity);
                        _ptr = _alloc_copy.allocate(this->_capacity + 1);
                    }
                    else
                    {
                        _alloc_copy.deallocate(_ptr, this->_capacity);
                        _ptr = temp;
                    }
                }
                _alloc_copy.construct(&_ptr[this->_size], val);
                this->_size++;
                if(_capacity == 0)
                    _capacity = 1;
            }

            void pop_back()
            {
                if(_size > 0)
                {
                    _alloc_copy.destroy(&_ptr[this->_size - 1]);
                    this->_size--;
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                difference_type diff;
                iterator        ret = end();
                
                diff = std::distance(begin(), position);
                // std::cout << "dis" << diff << std::endl;
                if(end() > begin() + diff)
                    push_back(val);
                else
                {
                    puts("herrrre");
                    resize(diff);
                    _alloc_copy.construct(&_ptr[_size - 1], val);
                }
                for(difference_type i = _size - 1; i > diff; i--)
                    std::swap(_ptr[i], _ptr[i - 1]);
                return begin() + diff; // return is not what we want
            }

            void   insert (iterator position, size_type n, const value_type& val)
            {
                difference_type diff;

                diff = std::distance(begin(), position);
                for(size_type i = 0; i < n; i++)
                    insert(begin() + diff + i, val);
            }
            
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!(is_integral<InputIterator>::value), int>::type = 0)
            {
                difference_type diff;
                difference_type length;

                diff = std::distance(begin(), position);
                length = std::distance(first, last);
                for(difference_type i = 0; i < length; i++)
                    insert(begin() + diff + i, *(first + i));
            }

            iterator erase (iterator position)
            {
                pointer     temp;
                int         index = 0;
                int         index1 = 0;

                temp = _alloc_copy.allocate(_capacity);
                for(iterator i = begin(); i != end(); i++)
                {
                    if(*i != *position)
                        _alloc_copy.construct(&temp[index1++], _ptr[index]);
                    _alloc_copy.destroy(&_ptr[index]);
                    index++;
                }
                _alloc_copy.deallocate(_ptr, _capacity);
                this->_size--;
                _ptr = temp;
                return position;
            }

            iterator erase (iterator first, iterator last)
            {
                difference_type diff;
                difference_type range;
                size_t          i;

                diff = std::distance(begin(), first);
                range = std::distance(first, last);
                for (i = diff; i < this->_size; i++)
                    std::swap(_ptr[i], _ptr[i + range]);
                this->_size -= range;
                iterator it(_ptr + diff);
                return it;
            }

            void swap (vector& x)
            {
                std::swap(this->_ptr, x._ptr);
                std::swap(this->_alloc_copy, x._alloc_copy);
                std::swap(this->_size, x._size);
                std::swap(this->_capacity, x._capacity);
            }
            
            void clear()
            {
                for(size_type i = 0; i < _size; i++)
                    _alloc_copy.destroy(&_ptr[i]);
                _size = 0;
            }

            //Allocator-------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return _alloc_copy;
            }
    };
    //Non-member function overloads------------------------------------------
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if(rhs.size() == lhs.size())
            return ft::equal(rhs.begin(), rhs.end(), lhs.begin());
        return false;
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
            if(rhs.size() != lhs.size())
            return !ft::equal(rhs.begin(), rhs.end(), lhs.begin());
        return false;
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif


//what does typename there