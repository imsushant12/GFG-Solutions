/*
Problem Statement:
-----------------
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
---------
Input:
   1
 /  \
3    2
Output: 1 3

Your Task: You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

// Code:
vector <int> result;
int maxLevel = 0;

void LVUtil(Node *root , int level)
{
    if(root == NULL)
        return;
    
    if(level >= maxLevel)
    {
        result.push_back(root->data);
        maxLevel++;
    }
    LVUtil(root->left , level+1);
    LVUtil(root->right , level+1);
}

vector<int> leftView(Node *root)
{
    result.clear();
    int level = 0;
    LVUtil(root , level);
    maxLevel = 0;
    return result;
}
