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
        // typedef reverse_iterator<iterator> reverse_iterator;
        // typedef reverse_iterator<const_iterator> const_reverse_iterator;

        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;

    private:
        pointer _ptr;
       
    public:

        //member fuctions---------------------------------

        //Constructors
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            
        }

        explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type())
        {

        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type())
        {

        }

        vector (const vector& x)
        {

        }

        //Destructor
        ~vector()
        {

        }

        //assignement overload
        vector& operator= (const vector& x)
        {

        }

        //iterators------------------------------------
        iterator begin()
        {
           
        }

        const_iterator begin() const
        {

        }

        iterator end()
        {

        }
        const_iterator end() const
        {

        }

        iterator rbegin()
        {
           
        }

        const_iterator rbegin() const
        {

        }

        iterator rend()
        {

        }
        const_iterator rend() const
        {

        }

        //Capacity--------------------------------------------
        size_type size() const
        {

        }

        size_type max_size() const
        {

        }

        void resize (size_type n, value_type val = value_type())
        {

        }

        size_type capacity() const
        {

        }

        bool empty() const
        {

        }

        void reserve (size_type n)
        {

        }

        //Element Access--------------------------------------------
        reference operator[] (size_type n)
        {

        }

        const_reference operator[] (size_type n) const
        {

        }

        reference at (size_type n)
        {

        }

        const_reference at (size_type n) const
        {

        }

        reference front()
        {
        
        }
        const_reference front() const
        {

        }

        reference back()
        {
        
        }
        const_reference back() const
        {

        }

        //Modifiers------------------------------------------------------
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {

        }

        void assign (size_type n, const value_type& val)
        {

        }

        void push_back (const value_type& val)
        {

        }

        void pop_back()
        {

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