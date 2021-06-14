/*
Problem Statement:
-----------------
Given two BSTs, return elements of both BSTs in sorted form.

Example 1:
---------
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.

Example 2:
---------
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
    
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.

Your Task: You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs 
as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.

Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).
*/

// Link --> https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1#

// Code:
class Solution
{
    public:
    vector<int> answer;
    
    void inorder(Node *root)
    {
        if(root == NULL)
            return;
        answer.push_back(root->data);
        inorder(root->left);
        inorder(root->right);
    }
    
    vector<int> merge(Node *root1 , Node *root2)
    {
       answer.clear();
       
       inorder(root1);
       inorder(root2);
       sort(answer.begin() , answer.end());
       
       return answer;
    }
};
