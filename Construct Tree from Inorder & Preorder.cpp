/*
Problem Statement:
-----------------
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:
---------
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1

Example 2:
---------
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0

Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

Your Task: Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) 
and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically 
(The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/construct-tree-1/1#

// Code:
class Solution
{
    public:
    
    int findIndex(int a[] , int start , int target)
    {
        int i=0;
        while(a[start+i] != target) 
            i++;
        return i;
    }
    
    Node* buildUtil(int in[] , int pre[] , int inStart , int preStart , int n)
    {
        if(n==0) 
            return NULL;
        
        Node* ret = new Node(pre[preStart]);
        
        int i = findIndex(in , inStart , pre[preStart]);
        
        ret->left = buildUtil(in , pre , inStart , preStart+1 , i);
        ret->right = buildUtil(in , pre , inStart+i+1 , preStart+i+1 , n-i-1);
        
        return ret;
    }
    
    Node *buildTree(int in[] , int pre[] , int n)
    {
        return buildUtil(in , pre , 0 , 0 , n);
    }
};
