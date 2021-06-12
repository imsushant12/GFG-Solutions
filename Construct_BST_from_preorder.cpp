/*
Problem Statement:
-----------------
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50
*/

// Link --> https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if(root == NULL)
        return;
    
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}

int index = 0;
Node* constructBST(int pre[] , int data , int min , int max , int n)
{
    if(index > n)
        return NULL;
    
    Node *newNode = NULL;

    if(data < max and data > min)
    {
        newNode = new Node(data);
        index++;

        if(index < n)
            newNode->left = constructBST(pre , pre[index] , min , data , n);

        if(index < n)
            newNode->right = constructBST(pre , pre[index] , data , max , n);
    }

    return newNode;    
}

int main()
{
    int pre[] = {10 , 5 , 1 , 7 , 40 , 50};
    int n = sizeof(pre)/sizeof(pre[0]);

    // we will pass pre-order array and n i.e. size of the array,
    // along with that current data i.e. 0 and its range i.e min to max.
    Node* root = constructBST(pre , pre[0] , INT_MIN , INT_MAX , n);

    preorder(root);

    return 0;
}
