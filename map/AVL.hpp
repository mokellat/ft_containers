#include <iostream>

class Node 
{
   public:
      int   key;
      Node  *left;
      Node  *right;
      int   height;
};

// Calculate height

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

Node    *rotatate_left(Node *x)
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
	Node *right = node->right;
	Node *left = node->left;

	if(node == NULL)
		return 0;
	return right->height - left->height;
}

Node  *insertNode(Node *root, int key)
{
	int bf;
    // explain the recursion happening here
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
	}
	else if(bf < -1)
	{
		// means the height of the right subtree is greater than that of the left subtree

	}
}