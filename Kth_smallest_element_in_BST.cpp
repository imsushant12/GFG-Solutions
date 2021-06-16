/*
Problem Statement:
-----------------
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:
---------
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
----------
Input:
        2
      /  \
     1    3
K = 5
Output: -1
 
Your Task: You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST 
and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

// Link --> https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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
    
    int KthSmallestElement(Node *root , int k)
    {
        in.clear();
        inorder(root);
        
        if(in.size() >= k)
            return in[k-1];
        else
            return -1;
    }
};
