/*
Problem Statement:
------------------
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. 
In case, if the either of predecessor or successor is not found print -1.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.
Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.
Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100
Output:
60 70
80 -1
*/

// Link --> https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

// Code:
Node* maximum(Node *root)
{
    if(root == NULL)
        return NULL;
    
    while(root->right != NULL)
        root = root->right;
    
    return root;
}

Node* temp = NULL;
void findPreSuc(Node* root , Node*& pre , Node*& suc , int key)
{
    if(root == NULL)  
        return ;
    
    if(root->key == key)
    {
        if(root->left != NULL)
        {
            temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp ;
        }
 
        if(root->right != NULL)
        {
            temp = root->right ;
            while(temp->left)
                temp = temp->left ;
            suc = temp ;
        }
        return;
    }
 
    if(root->key > key)
    {
        suc = root ;
        findPreSuc(root->left , pre , suc , key) ;
    }
    
    else
    {
        pre = root ;
        findPreSuc(root->right , pre , suc , key) ;
    }
}
