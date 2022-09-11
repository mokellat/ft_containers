#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iterator>

namespace ft
{
    template <class Iterator>
    class iterator_traits
    {
        public :
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::iterator_category iterator_category;
    };
    
    template <class T>
    class iterator_traits<T*>
    {
        public :
            typedef ptrdiff_t						difference_type;
            typedef T								value_type;
            typedef T*								pointer;
            typedef T&								reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public :
            typedef const ptrdiff_t							difference_type;
            typedef const T									value_type;
            typedef const T*								pointer;
            typedef const T&								reference;
            typedef const std::random_access_iterator_tag	iterator_category;
    };

    //enable if
    template<bool Cond, class T = void> 
    struct enable_if 
    {

    };
    template<class T> 
    struct enable_if<true, T> 
    { 
        typedef T type;
    };

    //is_integral
    template <class T> 
    struct is_integral
    {

    };

    //equal
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1!=last1) 
        {
            if (!(*first1 == *first2))
            return false;
            ++first1; ++first2;
        }
        return true;
    };

    //lexicographical
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1) 
                return false;
            else if (*first1 < *first2) 
                return true;
            ++first1; ++first2;
        }
        return (first2 != last2);
    };

    //std::pair
    template <class T1, class T2> 
    struct pair
    {

    };

    //std::make_pair
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y));
    };
} 


#endif