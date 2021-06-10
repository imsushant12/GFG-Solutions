/*
Problem Statement:
-----------------
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:
---------
Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 

Your Task: You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree 
and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 105

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

// Link --> https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

// Code:
int findLevel(Node *root, int k, int level)
{
    if (root == NULL) 
        return -1;
        
    if (root->data == k) 
        return level;
        
    int l = findLevel(root->left, k, level + 1);
    
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}

Node *findDistU(Node *root , int n1 , int n2 , int &d1 , int &d2 , int &dist , int lvl) 
{
    if (root == NULL) 
        return NULL;
    if (root->data == n1) 
    {
        d1 = lvl;
        return root;
    }
    
    if (root->data == n2) 
    {
        d2 = lvl;
        return root;
    }

    Node *l = findDistU(root->left , n1 , n2 , d1 , d2 , dist , lvl+1);
    Node *r = findDistU(root->right , n1 , n2 , d1 , d2 , dist , lvl+1);

    if (l and r)
        dist = d1 + d2 - 2 * lvl;

    return (l != NULL) ? l : r;
}

int findDist(Node *root, int n1, int n2) 
{
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistU(root, n1, n2, d1, d2, dist, 1);
    
    if (d1 != -1 and d2 != -1) 
        return dist;

    if (d1 != -1) 
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
    
    if (d2 != -1) 
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
    
    return -1;
}
