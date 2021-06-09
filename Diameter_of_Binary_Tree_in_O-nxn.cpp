/*
Problem Statement:
-----------------
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. 

Example 1:
---------
Input:
       1
     /  \
    2    3
Output: 3

Example 2:
---------
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

Your Task: You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

// Code : 
class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int height(Node *root)
    {
        if(root == NULL)
            return 0;
     
        int lt = height(root->left);
        int rt = height(root->right); 
            
        return (1 + max(lt , rt));
    }
    
    int diameter(Node* root)
    {
        if(root == NULL)
            return 0;
        
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        int lht = height(root->left);
        int rht = height(root->right);
        int ht = lht + rht + 1;
        
        return(max(max (ld , rd) , ht));
    }

};
