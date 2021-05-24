/*
Problem Statement:
-----------------
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. 
The output nodes can be printed in any order. A node x is there in output if x is the topmost node at its horizontal distance. 
Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1. 

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
 
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/

// Link --> https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/

// Code:
#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> um;

struct Node
{
    int info;
    struct Node *left, *right;
};

struct Node* create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout << "\nEnter data to be inserted or type -1 : ";
    cin >> data;

    if(data == -1)
        return 0;

    tree->info = data;

    cout << "Enter left child of " << data;
    tree->left = create();

    cout << "Enter right child of " << data;
    tree->right = create();

    return tree;
};

void topView(Node *root, int level)
{
    if(root == NULL)
        return;

    int i = um.count(level);

    if(i == 0)
        um[level] = root->info;

    topView(root->left, level-1);
    topView(root->right, level+1);

    um[level] = root->info;

    return;
}

int main()
{
    Node *root = NULL;
    root = create();

    topView(root, 0);

    for(auto x : um)
        cout<<x.first<<" --> "<<x.second<<endl;

    return 0;
}
