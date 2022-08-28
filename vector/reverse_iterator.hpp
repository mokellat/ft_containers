#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "../library.hpp"

template<class iterator>
class reverse_iterator
{
    public:

        //Member functions
        
        //constructors
        reverse_iterator()
        {

        }

        explicit reverse_iterator (iterator_type it)
        {

        }

        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it)
        {

        }


        iterator_type base() const
        {

        }

        //operators
        reference operator*() const
        {

        }

        reverse_iterator operator+ (difference_type n) const
        {

        }

        reverse_iterator& operator++()
        {

        }

        reverse_iterator  operator++(int)
        {

        }

        reverse_iterator& operator+= (difference_type n)
        {

        }

        reverse_iterator operator- (difference_type n) const
        {

        }

        reverse_iterator& operator--()
        {

        }
        reverse_iterator  operator--(int)
        {

        }

        reverse_iterator& operator-= (difference_type n)
        {

        }

        pointer operator->() const
        {

        }

        reference operator[] (difference_type n) const
        {

        }

        //Non-member function overloads

        template <class Iterator>
        bool operator== (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }	
        template <class Iterator>
        bool operator!= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }	
        template <class Iterator>
        bool operator<  (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }	
        template <class Iterator>
        bool operator<= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }	
        template <class Iterator>
        bool operator>  (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }	
        template <class Iterator>
        bool operator>= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
        {

        }

        template <class Iterator>
        reverse_iterator<Iterator> operator+ (
                    typename reverse_iterator<Iterator>::difference_type n,
                    const reverse_iterator<Iterator>& rev_it)
        {

        }

        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
        {

        }
};

#endif