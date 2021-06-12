/*
Problem Statement:
-----------------
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 
Example 1:
---------
Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:
----------
Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

Your Task: You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree 
as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

// Code:
class Solution
{
  public:
 
    vector <int> in;
    void preorder(Node *root)
    {
        if(root == NULL)
            return;
        
        in.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
    int index = 0;
    void BST(Node *root)
    {
        if(root == NULL)
            return;
        
        BST(root->left);
        
        root->data = in[index++];
        
        BST(root->right);
    }
    
    Node* binaryTreeToBST(Node *root)
    {
        if(root == NULL)
            return NULL;
        
        preorder(root);
        sort(in.begin() , in.end());
        BST(root);
        
        return root;
    }
};
