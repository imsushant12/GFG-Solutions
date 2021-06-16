/*
Problem Statement:
-----------------
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.
The values smaller than root go to the left side. The values greater and equal to the root go to the right side.

Example 1:
---------
Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the range.

Example 2:
---------
Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the given range.

Your Task: This is a function problem. You don't have to take input. You are required to complete the function getCountOfNode() 
that takes root, l ,h as parameters and returns the count.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).
*/

// Link --> https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

// Code:
int counter = 0;
void inorder(Node *root , int l , int h)
{
    if(root == NULL)
        return;
    
    if(root->data >= l and root->data <= h)
    {
        counter++;
        inorder(root->left ,  l , h);
        inorder(root->right , l , h);
    }
    else if(root->data < l)
        inorder(root->right , l , h);
    else
        inorder(root->left , l , h);
}

int getCount(Node *root , int l , int h)
{
    counter = 0;
    inorder(root , l , h);
    
    return counter;
}
