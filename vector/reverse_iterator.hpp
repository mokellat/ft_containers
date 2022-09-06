#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "../utilities.hpp"

namespace ft
{

    template<class iterator>
    class reverse_iterator
    {

        public:
            typedef iterator                                                    iterator_type;
            typedef typename iterator_traits<iterator>::iterator_category       iterator_category;
            typedef typename iterator_traits<iterator>::value_type              value_type;
            typedef typename iterator_traits<iterator>::difference_type         difference_type;
            typedef typename iterator_traits<iterator>::pointer                 pointer;
            typedef typename iterator_traits<iterator>::reference               reference;

        private:
            iterator_type    _it;

        public:
            //Member functions

            //constructors
            reverse_iterator()  : _it() {}

            explicit reverse_iterator (iterator_type it)
            {
                _it = it;
            }

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                _it = rev_it._it;
            }


            iterator_type base() const
            {
                return _it;
            }

            //operators
            reference operator*() const
            {
                iterator_type _iter;

                _iter = _it;
                _iter--;
                return *_iter;
            }

            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator rev_it = *this;
                rev_it._it - n;
                return rev_it;
            }

            reverse_iterator& operator++()
            {
                _it--;
                return *this;
            }

            reverse_iterator  operator++(int)
            {
                reverse_iterator rev_it = *this;
                _it--;
                return rev_it;
            }

            reverse_iterator& operator+= (difference_type n)
            {
                reverse_iterator rev_it = *this;

                rev_it._it -= n;
                return rev_it;
            }

            reverse_iterator operator- (difference_type n) const
            {
                std::cout << "fuuuuuck" << std::endl;
                reverse_iterator rev_it = *this;
                rev_it._it + n;
                return rev_it;
            }

            reverse_iterator& operator--()
            {
                _it++;
                return *this;
            }

            reverse_iterator  operator--(int)
            {
                reverse_iterator rev_it = *this;
                _it++;
                return rev_it;
            }

            reverse_iterator& operator-= (difference_type n)
            {
                reverse_iterator rev_it = *this;

                rev_it._it += n;
                return rev_it;
            }

            pointer operator->() const
            {
                return *_it;
            }

            reference operator[] (difference_type n) const
            {
                return _it[n - 1];
            }
    };
    //Non-member function overloads

    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
        if(lhs._it == rhs._it)
            return true;
        else
            return false;
    }	
    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
            if(lhs._it != rhs._it)
            return true;
        else
            return false;
    }	
    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
            if(lhs._it > rhs._it)
            return true;
        else
            return false;
    }	
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
            if(lhs._it >= rhs._it)
            return true;
        else
            return false;
    }	
    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
            if(lhs._it < rhs._it)
            return true;
        else
            return false;
    }	
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
    {
            if(lhs._it <= rhs._it)
            return true;
        else
            return false;
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (
                typename reverse_iterator<Iterator>::difference_type n,
                const reverse_iterator<Iterator>& rev_it)
    {
        return rev_it + n;
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (
        const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs)
    {
        return lhs._it - rhs._it;
    }
}

#endif