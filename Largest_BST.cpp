/*
Problem Statement:
------------------
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Example 1:
---------
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Example 2:
---------
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a BST of size 2: 
       2
    /    \ 
   N      8
   
Your Task: You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary 
Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
*/

// Link --> https://practice.geeksforgeeks.org/problems/largest-bst/1#

// Code:
struct node1
{
    int isbst;
    int size;
    int mn;
    int mx;
};
struct node1 bst(struct Node *root)
{
    struct node1 x;
    if (root == NULL)
    {
        x.isbst = 1;
        x.size = 0;
        x.mn = 1000000;
        x.mx = 0;
        return x;
    }
    struct node1 left = bst(root->left);
    struct node1 right = bst(root->right);
    if (left.isbst == 1 && right.isbst == 1 && root->data > left.mx && root->data < right.mn)
    {
        x.isbst = 1;
        x.size = 1 + left.size + right.size;
        x.mx = max(root->data, right.mx);
        x.mn = min(root->data, left.mn);
    }
    else
    {
        x.isbst = 0;
        x.size = max(left.size, right.size);
        x.mn = 1000000;
        x.mx = 0;
    }
    return x;
};

int largestBst(Node *root)
{
    return bst(root).size;
}
