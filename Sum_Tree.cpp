/*
Problem Statement:
-----------------
Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value 
and its right subtree's value. Else return 0. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
A leaf node is also considered a Sum Tree.

Example 1:
---------
Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.

Example 2:
---------
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. 
Root element = 10 which is not equal to 30+40.

Your Task: You dont need to read input or print anything. Complete the function isSumTree() which takes root node as input parameter and 
returns true if the tree is a SumTree else it returns false.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)
*/

// Link --> https://practice.geeksforgeeks.org/problems/sum-tree/1#

// Code:
class Solution
{
    public:
    bool isLeaf(struct Node *node)
    {
        if(node == NULL)
            return false;
            
        if(node->left == NULL && node->right == NULL)
            return true;
            
        return false;
    }
    
    bool isSumTree(struct Node* node)
    {
        int ls; 
        int rs;
        
        if(node == NULL || isLeaf(node))
            return true;
    
        if(isSumTree(node->left) && isSumTree(node->right))
        {
            if(node->left == NULL)
                ls = 0;
            else if(isLeaf(node->left))
                ls = node->left->data;
            else
                ls = 2*(node->left->data);
    
            if(node->right == NULL)
                rs = 0;
            else if(isLeaf(node->right))
                rs = node->right->data;
            else
                rs = 2*(node->right->data);
    
            return(node->data == ls + rs);
        }
    
        return false;
    }

};
