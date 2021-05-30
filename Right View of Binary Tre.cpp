/*
Problem Statement:
-----------------
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:
---------
Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:
---------
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60

Your Task: Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

// Code:
class Solution
{
    public:
    
    vector <int> result;
    int maxLevel = 0;
    
    void RVUtil(Node *root , int level)
    {
        if(root == NULL)
            return;
        
        if(level >= maxLevel)
        {
            result.push_back(root->data);
            maxLevel++;
        }
        RVUtil(root->right , level+1);
        RVUtil(root->left , level+1);
    }
    
    vector<int> rightView(Node *root)
    {
        result.clear();
        int level = 0;
        RVUtil(root , level);
        maxLevel = 0;
        return result;
    }
};
