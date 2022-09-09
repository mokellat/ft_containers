#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <stdexcept>
#include <iterator>

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
                    const allocator_type& alloc = allocator_type())
            {
                // std::cout << "im heeeeeeeeeeeere" << std::endl;
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
                // for later i didnt get it right
                if(n < _size)
                {
                    for(size_type i = n; i < this->_size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                    _size = n;
                }
                else if(n > _size)
                {
                    for(size_type i = _size; i < n; i++)
                        push_back(val);
                    if(n > _capacity)
                    {
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
                if(n > max_size())
                    throw std::length_error("Lenght Error : Max size execeded");
                if(n > this->_capacity)
                {
                    size_type   i;
                    pointer     temp;

                    this->_capacity = n;
                    temp = _alloc_copy.allocate(n);
                    for(i = 0; i < this->_size; i++)
                    {
                        _alloc_copy.construct(&temp[i], _ptr[i]);
                        _alloc_copy.destroy(&_ptr[i]);
                    }
                    _alloc_copy.deallocate(_ptr, this->_size);

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
            void assign (InputIterator first, InputIterator last)
            {
                // std::cout << "first" << std::endl;
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
                // std::cout << "second" << std::endl;
                size_type i;

                if(_ptr)
                {
                    for(i = 0; i < _size; i++)
                        _alloc_copy.destroy(&_ptr[i]);
                }
                if(n > this->_capacity)
                {
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
                    _alloc_copy.deallocate(_ptr, this->_capacity);
                    _ptr = temp;
                } 
                _alloc_copy.construct(&_ptr[this->_size], val);
                this->_size++;
            }

            void pop_back()
            {
                _alloc_copy.destroy(&_ptr[this->_size - 1]);
                this->_size--;
            }

            iterator insert (iterator position, const value_type& val)
            {
                pointer     temp;
                size_type   j = 0;
                size_type   index = 0;
                // iterator    ret;

                if(*position == *(end()))
                {
                    // std::cout << "tababaaaaaaabine" << std::endl;
                    push_back(val);
                }
                else
                {
                    std::cout << "tababaaaaaaabine" << std::endl;
                    if(_size + 1 > _capacity)
                        _capacity *= 2;
                    temp = _alloc_copy.allocate(this->_capacity);
                    for(iterator i = begin(); i != end(); i++)
                    {
                        if(i == position)
                        {
                            std::cout << "constructed" << std::endl;
                            std::cout << *position << std::endl;
                            _alloc_copy.construct(&temp[j++], val);
                        }
                        _alloc_copy.construct(&temp[j], _ptr[index]);
                        _alloc_copy.destroy(&_ptr[index]);
                        index++;
                        j++;
                    }
                    _alloc_copy.deallocate(_ptr, this->_capacity);
                    _ptr = temp;
                    _size++;
                }
                return position;
            }

            void   insert (iterator position, size_type n, const value_type& val)
            {
                for(iterator i = position; i != position + n; i++)
                {
                    for (size_type i = 0; i < _size; i++)
                    {
                        std::cout << _ptr[i] << std::endl;
                    }
                    std::cout << "----------------------------" << std::endl;
                    insert(i, val);
                }
            }
            
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last)
            // {

            // }

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

                _ptr = _alloc_copy.allocate(_capacity);
                this->_size--;
                _ptr = temp;
                return position;
            }

            iterator erase (iterator first, iterator last)
            {
                for(iterator i = first; i!= last; i++)
                    erase(i);
                if(*last != *end())
                    return last + 1;
                else    
                    return first + 1;
            }

            void swap (vector& x)
            {
                // !!PS: Exception safety to ask for
                pointer     p1;
                pointer     p2;

                if(this->_size == x._size)
                {
                    for(size_type i = 0; i < this->_size; i++)
                       std::swap(_ptr[i], x._ptr[i]);
                }
                else
                {
                    // std::cout << "tabbbbb" << std::endl;
                    p1 = _alloc_copy.allocate(_size);
                    p2 = _alloc_copy.allocate(x._size);
                    for(size_type i = 0; i < x._size; i++)
                    {
                        _alloc_copy.construct(&p1[i], x._ptr[i]);
                        _alloc_copy.construct(&p2[i], _ptr[i]);
                        _alloc_copy.destroy(&x._ptr[i]);
                        _alloc_copy.destroy(&_ptr[i]);
                    }
                    for(size_type i = x._size; i < _size; i++)
                    {
                        _alloc_copy.construct(&p2[i], _ptr[i]);
                        _alloc_copy.destroy(&_ptr[i]);
                    }
                    _alloc_copy.deallocate(_ptr, this->_capacity);
                    _alloc_copy.deallocate(x._ptr, x._capacity);

                    //swapping after destroying originals and copying to temps
                    _ptr = p1;
                    x._ptr = p2;
                    std::swap(x._size, _size);
                }
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
        if(rhs._size == lhs._size)
            return std::equal(rhs.begin(), rhs.end(), lhs.begin());
        return false;
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
            if(rhs._size != lhs._size)
            return !std::equal(rhs.begin(), rhs.end(), lhs.begin());
        return false;
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif


//what does typename there