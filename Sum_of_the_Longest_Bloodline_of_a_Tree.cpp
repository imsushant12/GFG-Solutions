/*
Problem Statetment:
------------------
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:
---------
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13

Example 2:
---------
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree 
as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

// Code:
lass Solution
{
public:
    void sumOfLongRootToLeafPathUtil(Node *root , int sum , int len , int &maxLen , int &maxSum)
    {
        if(!root)
        {
            if(maxLen < len)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(maxLen == len && maxSum < sum)
                maxSum = sum;
            return;
        }
        sumOfLongRootToLeafPathUtil(root->left , sum + root->data , len+1 , maxLen , maxSum);
        sumOfLongRootToLeafPathUtil(root->right , sum + root->data , len+1 , maxLen , maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root)
            return 0;
        int maxSum = INT_MIN , maxLen = 0;
        sumOfLongRootToLeafPathUtil(root , 0 , 0 , maxLen , maxSum);
        return maxSum;
    }
};
