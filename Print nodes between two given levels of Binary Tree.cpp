/*
Problem Statement:
-----------------
Given a binary tree and two level numbers ‘low’ and ‘high’, print nodes from level low to level high.

For example consider the binary tree given in below diagram. 
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Input: Root of below tree, low = 2, high = 3

Output:
2 3
4 5 6 7
*/

// Link --> https://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers/

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

void printElements(Node* root , int level1 , int level2 , int level)
{
    if(root == 0)
        return;

    if(level >= level1 && level <= level2)
        cout<<root->info<<"   ";

    printElements(root->left , level1 , level2 , level+1);
    printElements(root->right , level1 , level2 , level+1);
}

int main()
{
    Node *root = NULL;
    root = create();

    int level1 = 2;
    int level2 = 4;

    printElements(root , level1 , level2 , 1);

    for(auto x : um)
        cout<<x.first<<" --> "<<x.second<<endl;

    return 0;
}



