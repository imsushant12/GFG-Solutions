/*
Problem Statement:
------------------
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes 
visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
---------
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
---------
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Your Task: Since this is a function problem. You don't have to take input. Just complete the function topView() 
that takes root node as parameter and returns a list of nodes visible from the top view from left to right. 
Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

// Code:
class Solution
{
    public:
    
    vector <int> topView(Node *root)
    {
        vector <int> ans;
        
        if(root == NULL)
            return ans;
    
        Node *temp = NULL;

        queue <pair <Node* , int>> q;
  
        map<int , int> mp;
    
        q.push({root, 0});
        
        while(!q.empty())
        {
    
            temp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            if(mp.find(d) == mp.end())
                mp[d] = temp->data;
    
            if(temp->left)
                q.push({temp->left, d-1});
            
            if(temp->right)
                q.push({temp->right, d+1});
        }
       
        for(auto it = mp.begin(); it != mp.end(); it++)
            ans.push_back(it->second);

        return ans;
    }

};

