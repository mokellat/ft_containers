
    if( (root->left != NULL) && (root->right == NULL) )
    {
        AVL_Node *temp = root->left;

        if (root->parent != NULL) 
        {
            if (root->parent->key < root->key)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;

            /*
                Update the height of root's parent
            */
            update_height(root->parent);
        }
        root->left->parent = root->parent;
    /*
        One child case
    */
    *root = *temp; /*
        Copy the contents of the non-empty child
    */
    free(temp);
}
else if((root->left == NULL) && (root->right != NULL))
{
    AVL_Node *temp = root->right;
    
    if (root->parent != NULL) {
        if (root->parent->key < root->key)
            root->parent->right = root->right;
        else
            root->parent->left = root->right;

            /*
                Update the height of root's parent
            */
        update_height(root->parent);
    }
    root->right->parent = root->parent;
    /*
        One child case
    */
    *root = *temp; /*
        Copy the contents of the non-empty child
    */
    free(temp);
}
/*
    No child case
*/
else if ((root->left == NULL) && (root->right == NULL))
{
    if (root->parent->key < root->key) {
        root->parent->right = NULL;
    }
    else {
        root->parent->left = NULL;
    }
    if (root->parent != NULL)
        update_height(root->parent);
    AVL_Node *temp = root;
    root = NULL;
}
else{
    /*
        AVL_Node with two children: Get the inorder successor (smallest in the right subtree)
    */
    AVL_Node* temp = minValueAVL_Node(root->right);
    /*
        Copy the inorder successor's data to this AVL_Node
    */
    root->key = temp->key;  
    /*
        Delete the inorder successor
    */
    root->right = AVL_delete(root->right,temp->key);
}
