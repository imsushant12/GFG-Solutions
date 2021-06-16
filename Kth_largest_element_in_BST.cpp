/*
Problem Statement:
-----------------
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:
---------
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:
---------
Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task: You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST 
and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)
*/

// Link --> https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#

// Code:
class Solution
{
    public:
    
    vector <int> in;
    void inorder(Node *root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);   
        in.push_back(root->data);
        inorder(root->right);
    }
    
    int kthLargest(Node *root , int k)
    {
        in.clear();
        inorder(root);
        return in[in.size()-k];
    }
};
