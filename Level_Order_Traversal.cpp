/*
Problem Statement:
-----------------
Given a binary tree, find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:
---------
Input:
    1
  /   \ 
 3     2
Output:1 3 2

Example 2:
---------
Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

Your Task: You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and 
returns a list of integers containing the level order traversal of the given Binary Tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

// Code:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

vector <int> result;
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector <int> levelOrder(Node* node)
    {
        result.clear();
            
        Node *temp;
        queue <Node*> q;
        
        q.push(node);
    
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
                
            result.push_back(temp->data);
        }
        return result;
    }
};
