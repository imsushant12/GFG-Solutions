/*
Problem Statement:
------------------
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:
---------
Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1

Example 2:
---------
Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Your Task: You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input 
parameter and returns a list containing the reverse level order traversal of the given tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

// Code:
/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 
*/

vector <int> result;

vector <int> reverseLevelOrder(Node *node)
{
    result.clear();
    
    Node *temp;
    queue <Node*> q;
        
    q.push(node);
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
            
        if(temp->right)
            q.push(temp->right);
            
        if(temp->left)
            q.push(temp->left);
                
        result.push_back(temp->data);
    }
    reverse(result.begin() , result.end());
    return result;
}
