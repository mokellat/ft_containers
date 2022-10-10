#pragma once

#include <iostream>
// #include "map_iterator.hpp"

template<class T>
class Node 
{
	// typedefs
	public:
		typedef T 								value_type;
		typedef Node<T>							node_type;
		typedef typename value_type::first_type	key_type;

	public:
		// T		value;
		// value_type								pair;
		value_type 								*key;
		Node									*parent;
		Node									*left;
		Node									*right;
		int										height;

	public:
		Node() : parent(), left(), right(), height(1) {}

		node_type    *MostRight(node_type *node)
		{
			// if(node != NULL)
			// {
			//     node_type *iter = node;

			//     while (iter->right != NULL)
			//         iter = iter->right;
			//     return iter;
			// }
			// else
			//     return NULL;
			if(node->right == NULL)
				return node;
			return MostRight(node->right);
		}

		node_type	*MostLeft(node_type *node)
		{
			if(node->left == NULL)
				return node;
			return MostLeft(node->left);
		}

		~Node(){}
};

// #include "map_iterator.hpp"

template<class T, class ALLoc, class Compare, class Main_Alloc>
class AVL
{

	//typedefs
	public:
		typedef T 								value_type;
		typedef typename value_type::first_type	key_type;
		// typedef ft::mapIterator<value_type>     iterator;
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

		void	root_print()
		{
			std::cout << root->key->first << std::endl; 
		}

		void	inorder_traversal(Node *node)
		{
			if(node == nullptr)
				return;
			inorder_traversal(node->left);
			std::cout << node->key->first << std::endl;
			inorder_traversal(node->right);
		}

		void printTree(Node *root, std::string indent, bool last) 
		{
			if (root != nullptr) {
				std::cout << indent;
			if (last) 
			{
				std::cout << "R---- ";
				indent += "   ";
			} 
			else 
			{
				std::cout << "L---- ";
				indent += "|  ";
			}
			std::cout << root->key->first << std::endl;
			printTree(root->left, indent, false);
			printTree(root->right, indent, true);
			}
		}


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

		// void update_height(AVL_Node* root)
		// {
		// 	if (root != NULL) 
		// 	{
		// 		int val = 1;
		// 		if (root->left != NULL)
		// 			val = root->left->height + 1;
		// 		if (root->right != NULL)
		// 			val = max(val, root->right->height + 1);
		// 		root->height = val;
		// 	}
		// }


		void	update_parent(Node *&node, Node *parent)
		{
			if(node == NULL)
				return;
			update_parent(node->right, node);
			node->parent = parent;
			update_parent(node->left, node);
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
			update_parent(y, x->parent);
			// we have to calculate the height of the nodes
			x->height = max(height(x->left),height(x->right)) + 1;
			y->height = max(height(y->left),height(y->right)) + 1;
			return y;
		}

		Node    *rotate_right(Node *y)
		{
			Node  *x;
			Node  *temp;

			x = y->left;
			temp = x->right;
			
			x->right = y;
			y->left = temp;
			update_parent(y, x->parent);
			// we have to calculate the height of the nodes
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			return x;
		}

		Node   *newNode(Node *neww, value_type key, Node *parent)
		{

			//allocating the whole node
			neww = _alloc_node.allocate(sizeof(Node *));
			_alloc_node.construct(neww);

			//allocating the value_type objcect
			neww->key =  _alloc_type.allocate(sizeof(neww->key));
			_alloc_type.construct(neww->key, key);

			neww->height = 1;
			neww->right = NULL;
			neww->left = NULL;
			neww->parent = parent;
			return neww;
		}

		int		BalanceFactor(Node *node)
		{
			if(node == NULL)
				return 0;
			return height(node->left) - height(node->right);
		}

		Node  *insertNode(Node *root, value_type key, Node *parent)
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
				return newNode(root, key, parent);

			//(2)
			if(_compare(key.first, root->key->first))
				root->left = insertNode(root->left, key, root);
			else if(_compare(root->key->first, key.first))
				root->right = insertNode(root->right, key, root);
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
					root = rotate_right(root);
					// return root;
				}
				else if(_compare(root->left->key->first, key.first))
				{
					//left-right rotation
					root->left = rotate_left(root->left);
					root = rotate_right(root);
				}
			}
			if(bf < -1)
			{
				// means the height of the right subtree is greater than that of the left subtree
				if(_compare(root->right->key->first, key.first))
				{
					//left rotation
					root = rotate_left(root);
					// return root;
				}
				else
				{
					//right-left rotation
					root->right = rotate_right(root->right);
					root = rotate_left(root);
				}
			}
			if(root->left)
				root->left->parent = root;
			if(root->right)
				root->right->parent = root;
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

		void	free_temp(Node *temp)
		{
			_alloc_node.destroy(temp);
			_alloc_node.deallocate(temp, sizeof(temp));
			// free(temp);
		}

		Node	*deleteOneNode(Node *root, key_type key)
		{
			// puts("heeeeeeeeeeeere");
			Node	*temp;
			int		bf;

			// locate the node to be deleted
			if(root == NULL)
				return root;
			if(_compare(root->key->first, key))
				root->right = deleteOneNode(root->right, key);
			else if(_compare(key, root->key->first))
				root->left = deleteOneNode(root->left, key);
			else
			{
				//found the node to be deleted
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
						// _alloc_node.destroy(temp);
						// _alloc_node.deallocate(temp, sizeof(temp));
						// free(temp);
					}
					// !! here we should delete the temp, they used free, we shouldnt
				}
				else
				{
					//the parent has two children, we have to find the inorder successor
					// it means the nide with minimum value in the right subtree

					Node *temp = MostLeft(root->right);
					root->key = temp->key;
					root->right = deleteOneNode(root->right, temp->key->first);
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
					root = rotate_right(root);
				else
				{
					root->left = rotate_left(root->left);
					root = rotate_right(root);
				}
			}
			if (bf < -1) 
			{
				if (BalanceFactor(root->right) <= 0) 
					root = rotate_left(root);
				else 
				{
					root->right = rotate_right(root->right);
					root = rotate_left(root);
				}
			}
			if (root->left)
				root->left->parent = root;
			if (root->right)
				root->right->parent = root;
			return root;
		}

		Node    *MostLeft(Node *node) const
		{
			if(node != NULL)
			{
				Node *iter = node;

				while (iter->left != NULL)
					iter = iter->left;
				return iter;
			}
			else
				return NULL;
		}

		Node    *MostRight(Node *node) const
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

			if (_compare(node->key->first, key) == true)
				return (SearchNode(node->right, key));
			else if (_compare(key, node->key->first) == true)
				return (SearchNode(node->left, key));
			return (node);
		}

		void	deleteAllNodes(Node *node)
		{
			if(node != NULL) 
			{
				deleteAllNodes(node->left);
				deleteAllNodes(node->right);
				_alloc_type.destroy(node->key);
				_alloc_type.deallocate(node->key, sizeof(node->key));
				// _alloc_node.destroy(node);
				_alloc_node.deallocate(node, sizeof(node));
				node = NULL;
			}
			// node = NULL;
		}
};