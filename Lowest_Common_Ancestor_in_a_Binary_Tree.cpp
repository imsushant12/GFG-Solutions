/*
Problem Statement:
-----------------
Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Example 1:
--------
Input:
n1 = 2 , n2 =  3
     1
   /  \
  2    3
Output: 1
Explanation: LCA of 2 and 3 is 1.

Example 2:
---------
Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2
Explanation: LCA of 3 and 4 is 2. 

Your Task: You don't have to read input or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns LCA node as output.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// Code:
class Solution
{
    public:
    
    Node* lca(Node* root , int n1 , int n2)
    {
        if(root == NULL)
            return NULL;
        
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node *lcaLeft = lca(root->left , n1 , n2);
        Node *lcaRight = lca(root->right , n1 , n2);
        
        if(lcaLeft && lcaRight)
            return root;
            
        if(lcaLeft == NULL)
            return lcaRight;
        else
            return lcaLeft;
    }
};
