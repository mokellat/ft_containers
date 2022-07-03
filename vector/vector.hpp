#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "library.hpp"

template < class T, class Alloc = std::allocator<T>>
class vector
{
    public:
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;

        // iterators
        typedef MyIterator<value_type>        iterator;
        typedef MyIterator<const value_type>  const_iterator;

        //reverse iterator
        // typedef reverse_iterator<iterator> reverse_iterator;
        // typedef reverse_iterator<const_iterator> const_reverse_iterator;
    private:

    
    public:
    //member fuctions
    vector()
    {

    }
    ~vector()
    {

    }
    vector &operator=(vector &it)
    {
        return (*this);
    }

    //iterators
};
#endif


//what does typename there