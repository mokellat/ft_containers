#include <iostream>

template<class T>
class Node 
{
	public:
		// T		value;
		T		key;
		Node	*left;
		Node	*right;
		int		height;

	public:
		Node() : height(1), left(NULL), right(NULL){}

		~Node(){}
		
};

template<class T>
class AVL
{
	private:
		Node	*_node

	public:
		AVL() : _node() {}

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

		Node   *newNode(int key)
		{
			Node *neww = new Node();
			neww->right = NULL;
			neww->left = NULL;
			neww->height = 1;
			neww->key = key;
			return neww;
		}

		int		BalanceFactor(Node *node)
		{
			if(node == NULL)
				return 0;
			return height(node->left) - height(node->right);
		}

		Node  *insertNode(Node *root, int key)
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
				return newNode(key);

			//(2)
			if(key > root->key)
				root->right = insertNode(root->right, key);
			else if(key < root->key)
				root->left = insertNode(root->left, key);
			else
				return root;

			//get the balance back and update the height
			root->height = max(height(root->left), height(root->right)) + 1;
			bf = BalanceFactor(root);
			if(bf > 1)
			{
				//means the height of the right subtree is greater then the left one
				if(key < root->left->key)
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
				if(key > root->right->key)
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

		Node	*deleteOneNode(Node *root, int key)
		{
			Node	*temp;
			int		bf;

			// locate the node to be deleted
			if(root == NULL)
				return root;
			if(key > root->key)
				root->right = deleteOneNode(root->right, key);
			else if(key < root->key)
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
						free(temp);
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
};