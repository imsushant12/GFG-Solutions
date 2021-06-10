/*
Problem Statement:
------------------
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :
----------
Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.

Example 2 :
-----------
Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree in the given binary tree.
 
Your Task: You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree 
as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.
*/

// Link --> https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

// Code:
unordered_map <string , int> un;
string countSubTree(Node* root)
{
    if(root == NULL)
        return "$";
    
    string str="";
    
    if(root->left == NULL && root->right == NULL)
    {
        str = to_string(root->data);
        return str;
    }
    
    str = str + to_string(root->data);
    str = str + countSubTree(root->left);
    str = str + countSubTree(root->right);
    
    un[str]++;
    
    return str;
}


bool dupSub(Node *root)
{
    un.clear();
    countSubTree(root);
    
    for(auto i : un)
        if(i.second >= 2)
            return true;
    
    return false;
}
