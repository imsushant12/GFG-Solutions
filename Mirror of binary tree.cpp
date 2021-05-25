/*
Problem Statement:
-----------------
Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Examples: 
--------
Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

*/

// Link --> https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
}root;

Node* createNode(int val)
{
    Node* newNode = new Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<"  ";
    inorder(root->right);
}

void mirror(Node* root , Node** mirrortree)
{
    if(root == NULL)
        return;

    *mirrortree  = createNode(root->val);
    mirror(root->left , &((*mirrortree)->right));
    mirror(root->right , &((*mirrortree)->left));
}

int main()
{

    Node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    cout<<"Inorder of original tree: ";
    inorder(tree);

    Node* mirrortree = NULL;
    mirror(tree , &mirrortree);

    cout<<"\nInorder of mirror tree: ";
    inorder(mirrortree);

    return 0;
}

