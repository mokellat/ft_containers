#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "library.hpp"

template < class T, class Alloc = std::allocator<T>>
class vector
{
    public:
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;

        // iterators
        typedef MyIterator<value_type>                      iterator;
        typedef MyIterator<const value_type>                const_iterator;

        //reverse iterator
        typedef reverse_iterator<iterator>                  reverse_iterator;
        typedef reverse_iterator<const_iterator>            const_reverse_iterator;

        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;

    private:
        pointer         _ptr;
        allocator_type  _alloc_copy;
        size_type       _size;
        size_type       _capacity;
       
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

        explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
        {
            _size = n;
            _capacity = n;
            _ptr = _alloc_copy.allocate(n);
            for(int i = 0; i < n; i++)
                _alloc_copy.construct(&_ptr[i], val);
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type())
        {
            difference_type diff = std::distance(first, last);
            _size = diff;
            _capacity = diff;
            //what if the difference is < 0
            _ptr = _alloc_copy.allocate(diff);
            for(int i = 0; i < diff; i++)
                _alloc_copy.construct(&_ptr[i], first++);
        }

        vector (const vector& x)
        {
            this->_size = x._size;
            this->_capacity = x._capacity;
            this->_alloc_copy = x._alloc_copy;
            *this = x;
        }

        //Destructor
        ~vector()
        {
            if(_ptr)
            {
                MyIterator it;

                for(int i = 0; i < _size; i++)
                    _alloc_copy.destroy(&_ptr[i]);
                _alloc_copy.deallocate(_ptr, this->_size);
            }
        }

        //assignement overload
        vector& operator=(const vector& x)
        {
            // deallocate and destroy whats in the container then copy
            if(_ptr)
            {
                for(int i = 0; i < this->_size; i++)
                    _alloc_copy.destroy(&ptr[i]);
                _alloc_copy.deallocate(_ptr, this->_size);
            }
            this->_alloc_copy = x._alloc_copy;
            _ptr = alloc_copy.allocate(x._size);
            for(int i = 0; i < x._size; i++)
                alloc_copy.construct(&_ptr[i], &x[i]);
            this->_size = x._size;
            // *this = x;
            return *this;
        }

        //iterators------------------------------------
        iterator begin()
        {
           return iterator(&_ptr[0]);
        }

        const_iterator begin() const
        {
            return const_iterator(&_ptr[0]);
        }

        iterator end()
        {
            return iterator(&_ptr[_size]);
        }
        const_iterator end() const
        {
            return const_iterator(&_ptr[_size]);
        }

        iterator rbegin()
        {
           return reverse_iterator(&_ptr[0]);
        }

        const_iterator rbegin() const
        {
            return const_reverse_iterator(&_ptr[0]);
        }

        iterator rend()
        {
            return reverse_iterator(&_ptr[_size]);
        }
        const_iterator rend() const
        {
            return const_reverse_iterator(&_ptr[_size]);
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
            // for later i didnt get it right
            if(val == nullptr)
            {
                if(n < this->_size)
                {

                }
                else if(n > this->_size)
                {

                }
                else if(n > this->_capacity)
                {

                }
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
                throw std::lenght_error("Lenght Error : Max size execeded");
            if(n > this->_capacity)
            {
                size_type   i;
                pointer     temp;

                this->_capacity = n;
                temp = _alloc_copy.allocate(n);
                for(i = 0; i < this->_size; i++)
                {
                    _alloc_copy.construct(&_temp[i], &_ptr[i]);
                    _alloc_copy.destroy(&_ptr[i]);
                }   
                _ptr = _alloc_copy.deallocate(_ptr, this->_size);

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
            size_type i;

            if(_ptr)
            {
                for(int i = 0; i < _size; i++)
                    _alloc_copy.destroy(&_ptr[i]);
            }
            difference_type diff = std::distance(first, last);
            if(diff > this->_capacity)
            {
                _ptr = _alloc_copy.deallocate(_ptr, this->_size)
                this->_capacity = this->_size;
                _ptr = _alloc.copy.allocate(this->_capacity);
            }
            this->_size = diff;
            for(i = 0; i < diff; i++)
                _alloc_copy.construct(&_ptr[i], first++);
        }

        void assign (size_type n, const value_type& val)
        {
           size_type i;

            if(_ptr)
            {
                for(int i = 0; i < _size; i++)
                    _alloc_copy.destroy(&_ptr[i]);
            }
            if(n > this->_capacity)
            {
                _ptr = _alloc.deallocate(_ptr, this->_size)
                this->_capacity = n;
                _ptr = _alloc.copy.allocate(this->_capacity);
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
                this->_capacity = this->_capacity + this->_capacity / 2;
                temp = _alloc_copy.allocate(this->_capacity);
                for(i = 0; i < this->_size; i++)
                {
                    _alloc_copy.construct(&_temp[i], &_ptr[i]);
                    _alloc_copy.destroy(&_ptr[i]);
                }
                _ptr = _alloc_copy.deallocate(_ptr, this->_capacity);
                _ptr = temp;
            } 
            _alloc_copy.construct(&_ptr[this->_size], val);
            this->_size++;
        }

        void pop_back()
        {
            _allocator_copy.destroy(&_ptr[this->_size - 1]);
            this->_size--;
        }

        iterator insert (iterator position, const value_type& val)
        {
            
        }

        void   insert (iterator position, size_type n, const value_type& val)
        {

        }
        
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {

        }

        iterator erase (iterator position)
        {
            
        }

        iterator erase (iterator first, iterator last)
        {

        }

        void swap (vector& x)
        {

        }

        void clear()
        {

        }

        //Allocator-------------------------------------------------------------
        allocator_type get_allocator() const
        {
            
        }

        //Non-member function overloads------------------------------------------
        template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }
    
        template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }
    
        template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }
    
        template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }
    
        template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }
    
        template <class T, class Alloc>
        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {

        }

        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
        {
            
        }
};
#endif


//what does typename there