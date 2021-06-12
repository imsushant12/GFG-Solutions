/*
Problem Statement:
-----------------
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:
---------
Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

Example 2:
----------
Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task: You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST 
and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
*/

// Link --> https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#

// Code:
Node* LCA(Node *root, int n1, int n2)
{
    Node *answer = NULL;
    
    if(root == NULL)
        return NULL;
    
    if(n1 < root->data and n2 < root->data)
        answer = LCA(root->left , n1 , n2);
    
    else if(n1 > root->data and n2 > root->data)
        answer = LCA(root->right , n1 , n2);
    
    else
    {
        answer = root;
        return answer;
    }
        
    return answer;
}
