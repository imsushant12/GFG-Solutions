/*
Problem Statement:
-----------------
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:
---------
Input: 
            1
          /   \
         2     3

Output: 1

Explanation: Leaves 2 and 3 are at same level.

Example 2:
---------
Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation: Leaves 10, 15 and 30 are not at same level.

Your Task: You dont need to read input or print anything. Complete the function check() which takes root node as input parameter 
and returns true/false depending on whether all the leaf nodes are at the same level or not.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
*/

// Link --> https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#

// Code:
class Solution
{
  public:
    /*You are required to complete this method*/
    int maxLevel = 0;
    bool checkUtil(Node *root , int level)
    {
        if(root == NULL)
            return true;
            
        bool answer = true;
        
        if(root->left == NULL and root->right == NULL)
        {
            if(maxLevel == 0)
            {
                maxLevel = level;
            }
            else if(maxLevel != level)
            {
                return false;
            }
        }
        return(checkUtil(root->left , level+1) && checkUtil(root->right , level+1));
    }
    
    bool check(Node *root)
    {
        if(root == NULL)
            return true;
            
        if(checkUtil(root , 0))
            return true;
        else
            return false;
    }
};
