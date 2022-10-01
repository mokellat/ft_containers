#pragma once

#include <iostream>
#include <map>
#include "map_iterator.hpp"
#include "AVL.hpp"
#include <functional>
#include "map_reverse_iterator.hpp"
#include "node_helper.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
    class map
    {
        public:
            typedef	Key	                                        key_type;
			typedef T	                                        mapped_type;
			typedef pair<const key_type, mapped_type>	        value_type;
			typedef	Compare	                                    key_compare;
			typedef Alloc	                                    allocator_type;
			typedef	typename allocator_type::reference          reference;
			typedef	typename allocator_type::const_reference    const_reference;
			typedef	typename allocator_type::pointer	        pointer;
			typedef	typename allocator_type::const_pointer	    const_pointer;
			typedef ptrdiff_t	                                difference_type;

            //create an iterator bidericotinal and reverse iterator bellow

            typedef mapIterator<value_type>                     iterator;
            typedef mapIterator<const value_type>               const_iterator;

            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

			typedef	size_t	                                    size_type;

            //rebind and some typedefs for avl
            typedef Node<key_type>                              node_type;
		    typedef typename Alloc::rebind<node_type>::other         _alloc_node;  //it may throw error
            typedef AVL<key_type, _alloc_node, key_compare>     avl_type;

            //value compare
            class value_compare 
            {
                friend class map;

                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                
                public:
                    typedef bool        result_type;
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };

        private:
            //attributes(we ll see later)

            // Node<value_type>            *_node;

            avl_type            _avl_tree;
            allocator_type      _alloc_copy;
            key_compare         _comp;
            size_type           _size;

        public:

            //constructors-----------------------------------------
            explicit map (const key_compare& comp = key_compare(),
                            const allocator_type& alloc = allocator_type()) : _avl_tree(), _comp(comp)
            {
                _alloc_copy = alloc;
                _size = 0;
            }
            	
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
                            const allocator_type& alloc = allocator_type()) : _avl_tree(), _comp(comp)
            {
                _alloc_copy = alloc;
                _size = std::distance(first, last);
                insert(first, last);
            }
        	
            map (const map& x) : _avl_tree()
            {
                _size = x._size;
                _alloc_copy = x._alloc_copy;
                _comp = x._comp;
                insert(x.begin(), x.end());
            }

            //destructor---------------------------------------------
            ~map()
            {
                clear();
            }

            //equal overload---------------------------------------------
            map& operator= (const map& x)
            {
                clear();
                _alloc_copy = x._alloc_copy;
                _comp = x._comp;
                insert(x.begin(), x.end());
                return *this;
            }

            //iterators-------------------------------------
            iterator begin()
            {
                return iterator(MostLeft(_avl_tree.root));
            }

            const_iterator begin() const
            {
                return const_iterator(MostLeft(_avl_tree.root));
            }

            iterator end()
            {

            }

            const_iterator end() const
            {

            }

            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }

            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }

            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }

            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            }


            //capacity-------------------------------------
            bool empty() const
            {
                bool ret = true ? _size != 0 : false;
                return ret;
            }

            size_type size() const
            {
                return _size;
            }

            size_type max_size() const
            {
                return _alloc_copy.max_size();
            }

            //Element access--------------------------------------------------
            mapped_type& operator[] (const key_type& k)
            {
                return (*insert(make_pair(k,mapped_type())).first);
            }

            pair<iterator,bool> insert (const value_type& val)
            {
                iterator                it; // what should we initiliaze this iterator
                pair<iterator, bool>    p;
                
                if(!_avl_tree.SearchNode(_avl_tree.root, val->first, it))
                {
                    // we didn't find another node with the same value
                    _size++;
                    _avl_tree.root = _avl_tree.insertNode(_avl_tree.root, val->second);
                    return(pair<it, true>);
                }
                else
                {
                    // the element is not inserted, returning an iterator to this existing element (if the function returns a value).
                   return(pair<it, false>)
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                //Notice that this is just a hint and does not force the new element to be inserted at that position within 
                // the map container (the elements in a map always follow a specific order depending on their key).

                insert(val);
                return position;
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    insert(*first++);
                }
            }

            void erase (iterator position)
            {
                if(searchNode(_avl_tree.root, (*position)->first, NULL))
                {
                    // we found that the key is there
                    // we start erasing
                    _size--;
                    _avl_tree.root = _avl_tree.deleteOneNode(_avl_tree.root, (*position)->first);
                }
            }	

            size_type erase (const key_type& k)
            {
                 if(searchNode(_avl_tree.root, k, NULL))
                {
                    // we found that the key is there
                    // we start erasing
                    _size--;
                    _avl_tree.root = _avl_tree.deleteOneNode(_avl_tree.root, k);
                    return 1;
                }
                return 0;
            }	

            void erase (iterator first, iterator last)
            {
                while(first != last)
                {
                    erase(first);
                    first++;
                }
            }

            void swap (map& x)
            {
                std::swap(_avl_tree, x._avl_tree);
                std::swap(_alloc_copy, x._alloc_copy);
                std::swap(_size, x._size);
            }

            void clear()
            {
                //implement a function to delete all nodes
                _size = 0;
                _avl_tree.deleteAllNodes(_avl_tree.root, _alloc_node);
            }

            //Observers--------------------------------------------------
            key_compare key_comp() const
            {
                return _comp;
            }

            value_compare value_comp() const
            {
                return value_compare(_comp);
            }

            //operations---------------------------------------------------
            iterator find (const key_type& k)
            {
                iterator it;

                if(!_avl_tree.SearchNode(_avl_tree.root, k, it))
                    it(end());
                return it;
            }

            const_iterator find (const key_type& k) const
            {
                iterator it;

                if(!_avl_tree.SearchNode(_avl_tree.root, k, it))
                    it(end());
                return it;
            }

            size_type count (const key_type& k) const
            {
                if(!_avl_tree.SearchNode(_avl_tree.root, k, NULL))
                    return 0;
                return 1;
            }

            // iterator lower_bound (const key_type& k)
            // {
            //     iterator  it = end();

            //     if(_avl_tree.SearchNode(_avl_tree, ))
            //     return it;
            // }

            // const_iterator lower_bound (const key_type& k) const   
            // {

            // }

            // iterator upper_bound (const key_type& k)
            // {

            // }

            // const_iterator upper_bound (const key_type& k) const
            // {

            // }

            // pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            // {

            // }

            // pair<iterator,iterator>             equal_range (const key_type& k)
            // {

            // }


            allocator_type get_allocator() const
            {
                return _alloc_copy;
            }
    };
}