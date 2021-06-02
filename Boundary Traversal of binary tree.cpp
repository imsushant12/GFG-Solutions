/*
Problem Statement:
------------------
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach 
when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node 
you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already 
included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

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
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22

Your Task: This is a function problem. You don't have to take input. Just complete the function printBoundary() that takes the root node as input 
and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

// Code:
class Solution 
{
public:
    vector <int> result;
    // For printing left boundary nodes.
    void printLeft(Node *root)
    {
        if(root == NULL)
            return;
            
        if(root->left)
        {
            result.push_back(root->data);
            printLeft(root->left);
        }
        else if(root->right)
        {
            result.push_back(root->data);
            printLeft(root->right);
        }
    }
    
    // For printing right boundary nodes.
    void printRight(Node *root)
    {
        if(root == NULL)
            return;
            
        if(root->right)
        {
            printRight(root->right);
            result.push_back(root->data);
        }
        else if(root->left)
        {
            printRight(root->left);
            result.push_back(root->data);
        }
    }
    
    // For printing leaf nodes.
    void printLeaf(Node *root)
    {
        if(root == NULL)
            return;
        
        printLeaf(root->left);
        
        if(root->left == NULL && root->right == NULL)
            result.push_back(root->data);
        
        
        printLeaf(root->right);
    }
    
    vector <int> printBoundary(Node *root)
    {
        result.clear();
        
        if(root == NULL)
            return result;
         
        result.push_back(root->data);
            
        printLeft(root->left);
            
        printLeaf(root->left);
        printLeaf(root->right);
            
        printRight(root->right);
        
        return result;
    }
};
