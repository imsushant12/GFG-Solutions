/*
Problem Statement:
------------------
Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST).
Height balanced BST means a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
----------
Input: nums = {1, 2, 3, 4}
Output: {3, 2, 1, 4}
Explanation: The preorder traversal of the following BST formed is {3, 2, 1, 4}:
     3
    /  \
   2    4
 /
1

Example 2:
---------
Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
Explanation: The preorder traversal of the following BST formed is {4,2,1,3,6,5,7} :
        4
       / \
      2   6
     / \  / \
    1   3 5  7
 

Your Task: You don't need to read or print anything. Your task is to complete the function sortedArrayToBST() which takes nums as input paramater 
and returns the preorder traversal of height balanced BST.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/

// Link --> https://practice.geeksforgeeks.org/problems/array-to-bst4443/1#

// Code:
class Solution 
{
public:
    struct Node
    {
        int data;
        Node *left , *right;
    };
    
    vector<int> answer;
    void preorder(Node *root)
    {
        if(root == NULL)
            return;
            
        answer.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
 
    Node* formTree(vector<int> &nums , int start , int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        
        Node *root = new Node;
        root->data = nums[mid];
        root->left = formTree(nums , start , mid - 1);
        root->right = formTree(nums , mid + 1 , end);

        return root;
    }
    
    vector<int> sortedArrayToBST(vector<int> &nums) 
    {
        answer.clear();
        
        Node *root = formTree(nums , 0 , nums.size()-1);
        preorder(root);
        
        return answer;
    }
};
