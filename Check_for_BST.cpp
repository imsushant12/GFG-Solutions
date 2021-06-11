/*
Problem Statement:
------------------
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
Example 1:
---------
Input:
    2
 /    \
1      3
Output: 1 
Explanation: The left subtree of root node contains node with key lesser than the root node’s key and the right subtree of root node contains node 
with key greater than the root node’s key. Hence, the tree is a BST.
Example 2:
---------
Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST.
Your Task: You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter 
and returns true if the given binary tree is BST, else returns false. 
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
*/

// Link --> https://practice.geeksforgeeks.org/problems/check-for-bst/1#

// Code:
class Solution
{
    public:
    bool checkBST(Node *root,int min,int max)
    {
        if(!root)
            return true;    
        if(root->data>min && root->data<max)
            return (checkBST(root->left,min,root->data) and 
                checkBST(root->right,root->data,max));

        return false;
    }

    bool isBST(Node* root) 
    {
    if(!root)
        return true;
    if(checkBST(root->left,INT_MIN,root->data) and 
            checkBST(root->right,root->data,INT_MAX))
        return true;
    return false;
    }
};
