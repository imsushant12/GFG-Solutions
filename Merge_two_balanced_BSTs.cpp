/*
Problem Statement:
------------------
You are given two balanced binary search trees e.g., AVL or Red Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. 
Let there be m elements in first tree and n elements in the other tree. Your merge function should take O(m+n) time.
*/

// Link --> https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout << "\nEnter data to be inserted or type -1 : ";
    cin >> data;

    if (data == -1)
        return 0;

    tree->data = data;

    cout << "Enter left child of " << data;
    tree->left = create();

    cout << "Enter right child of " << data;
    tree->right = create();

    return tree;
}

vector<int> v;
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}

Node *Balanced_BST(int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *root = new Node;
    root->data = v[mid];
    root->left = Balanced_BST(start, mid - 1);
    root->right = Balanced_BST(mid + 1, end);

    return root;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout<<"\nCreate the first tree :";
    root1 = create();

    cout<<"\nCreate the second tree :";
    root2 = create();

    inorder(root1);
    inorder(root2);
    // We will sort the merged array(vector) to obtain the inorder of merged tree.
    sort(v.begin(), v.end());

    cout<<"\nInorder of the merged tree is : ";
    for(int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<"  ";


    Node *mergedRoot = Balanced_BST(0, v.size() - 1);

    cout << "\nPreorder traversal of the tree after balancing : ";
    preorder(mergedRoot);

    return 0;
}
