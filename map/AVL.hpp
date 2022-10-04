#pragma once

#include <iostream>
// #include "map_iterator.hpp"

template<class T>
class Node 
{
	// typedefs
	public:
		typedef T 								value_type;
		typedef typename value_type::first_type	key_type;

	public:
		// T		value;
		value_type								pair;
		value_type 								*key;
		Node									*parent;
		Node									*left;
		Node									*right;
		int										height;

	public:
		Node() : height(1), left(), right(), parent(){}

		~Node(){}
};

#include "map_iterator.hpp"

template<class T, class ALLoc, class Compare, class Main_Alloc>
class AVL
{

	//typedefs
	public:
		typedef T 								value_type;
		typedef typename value_type::first_type	key_type;
		typedef ft::mapIterator<value_type>     iterator;
		typedef	Main_Alloc						alloc_type;


	//some typedefs to add
	public:
		// typedef T								key_type;
		typedef Node<value_type>				Node;	
		typedef	Compare							compare;
		typedef	ALLoc							alloc_node;

	public:
		Node									*root;
		compare									 _compare;
		alloc_node								_alloc_node;
		alloc_type								_alloc_type;

	public:
		AVL() : root() {}

		~AVL() {}
	// Calculate height

	public:

		int height(Node *node)
		{
			if (node == NULL)
				return 0;
			return node->height;
		}

		int max(int a, int b) 
		{
			return (a > b) ? a : b;
		}

		Node    *rotate_left(Node *x)
		{
			Node  *y;
			Node  *temp;

			y = x->right;
			temp = y->left;
			//rotate here
			y->left = x;
			x->right = temp;
			// we have to calculate the height of the nodes
			y->height = max(height(y->left),height(y->right)) + 1;
			x->height = max(height(x->left),height(x->right)) + 1;
			return y;
		}

		Node    *rotate_right(Node *y)
		{
			Node  *x;
			Node  *temp;

			x = y->left;
			temp = x->right;
			//rotate here
			x->right = y;
			y->left = temp;
			// we have to calculate the height of the nodes
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			return x;
		}

		Node   *newNode(Node *neww, value_type key)
		{
			// we have to change it with the allocator
			neww->height = 1;
			neww->key =  _alloc_type.allocate(sizeof(neww->key));
			_alloc_type.construct(neww->key, key);
			neww = _alloc_node.allocate(neww->height * sizeof(neww));
			_alloc_node.construct(neww->key, key);
			neww->right = NULL;
			neww->left = NULL;
			return neww;
		}

		int		BalanceFactor(Node *node)
		{
			if(node == NULL)
				return 0;
			return height(node->left) - height(node->right);
		}

		Node  *insertNode(Node *root, value_type key)
		{
			int bf;

			// explaining the recursion happening here
			// so we all know that recursion stops when the condition is false
			// here we have two conditions
			// (1) : so the program gonna check the first to compare keys and see where the right
			// position to insert the node
			// (2) : we update the height and start checking the balance factor and start 
			// the rotations

			//(1)
			if(root == NULL)
				return newNode(root, key);

			//(2)
			if(_compare(root->key->first, key.first))
				root->right = insertNode(root->right, key);
			else if(_compare(key.first, root->key->first))
				root->left = insertNode(root->left, key);
			else
				return root;

			//get the balance back and update the height
			root->height = max(height(root->left), height(root->right)) + 1;
			bf = BalanceFactor(root);
			if(bf > 1)
			{
				//means the height of the right subtree is greater then the left one
				if(_compare(key.first, root->left->key->first))
				{
					//right rotation
					root->right = rotate_right(root->right);
					return root;
				}
				else
				{
					//left-right rotation
					root->left = rotate_left(root->left);
					return rotate_right(root);
				}
			}
			else if(bf < -1)
			{
				// means the height of the right subtree is greater than that of the left subtree
				if(_compare(root->right->key->first, key.first))
				{
					//left rotation
					root->left = rotate_left(root->left);
					return root;
				}
				else
				{
					//right-left rotation
					root->right = rotate_right(root->right);
					return rotate_left(root);
				}
			}
			return root;
		}

		Node	*inorderSuccessor(Node *node)
		{
			Node *temp;

			temp = node;
			while(temp->right != NULL)
				temp = temp->right;
			return temp;
		}

		Node	*deleteOneNode(Node *root, key_type key)
		{
			Node	*temp;
			int		bf;

			// locate the node to be deleted
			if(root == NULL)
				return root;
			if(_compare(root->key > key))
				root->right = deleteOneNode(root->right, key);
			else if(_compare(key > root->key))
				root->left = deleteOneNode(root->left, key);
			else
			{
				//found the node to be deleted
				// if(root->right == NULL && root->left == NULL)
				// {
				// 	// no childs, delete the node immeadiately
				// 	std::cout << "im fucking here" << std::endl;
				// }
				if(root->right == NULL || root->left == NULL)
				{
					// has one child, replace the parent with the child
					if(root->right == NULL)
						temp = root->left;
					else
						temp = root->right;
					if(temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
					{
						*root = *temp;
						_alloc_node.destroy(temp);
						_alloc_node.deallocate(temp, sizeof(temp));
						// free(temp);
					}
					// !! here we should delete the temp, they used free, we shouldnt
				}
				else
				{
					//the parent has two children, we have to find the inorder successor
					// it means the nide with minimum value in the right subtree

					Node *temp = inorderSuccessor(root->right);

					root->key = temp->key;
					root->right = deleteOneNode(root->right, temp->key);
				}
			}

			if(root == NULL)
				return NULL;
			//update the height and get the tree balanced 
			//rotations here

			root->height = 1 + max(height(root->left), height(root->right));
			bf = BalanceFactor(root);
			if (bf > 1) 
			{
				if (BalanceFactor(root->left) >= 0) 
					return rotate_right(root);
				else
				{
					root->left = rotate_left(root->left);
					return rotate_right(root);
				}
			}
			if (bf < -1) 
			{
				if (BalanceFactor(root->right) <= 0) 
					return rotate_left(root);
				else 
				{
					root->right = rotate_right(root->right);
					return rotate_left(root);
				}
			}
			return root;
		}

		Node    *MostLeft(Node *node)
		{
			if(node != NULL)
			{
				Node *iter = node;

				while (iter->left != NULL)
					iter = iter->_left;
				return iter;
			}
			else
				return NULL;
		}

		Node    *MostRight(Node *node)
		{
			if(node != NULL)
			{
				Node *iter = node;

				while (iter->right != NULL)
					iter = iter->right;
				return iter;
			}
			else
				return NULL;
		}

		// checks if a node exits
		Node    *SearchNode(Node *node, key_type key)
		{
			if(node == NULL)
				return NULL;
			if(node->key->first == key)
				return node;

			Node *res1 = SearchNode(node->left, key);
			if(res1)
				return res1;
			Node *res2 = SearchNode(node->right, key);
			if(res2)
				return res2;
			return NULL;
		}

		void	deleteAllNodes(Node *node)
		{
			if(node != NULL) 
			{
				deleteAllNodes(node->left);
				deleteAllNodes(node->right);
				_alloc_node.destroy(node);
				_alloc_node.deallocate(node, sizeof(node));
			}
			node = NULL;
		}
};