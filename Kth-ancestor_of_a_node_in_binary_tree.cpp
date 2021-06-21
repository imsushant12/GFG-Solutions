/*
Problem Statement:
-----------------
Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the given node in the binary tree. 
If there does not exist any such ancestor then print -1.
*/

// Link --> https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

// Code:
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printNode(vector<int> &path, int K)
{
    if (path[path.size() - K])
        cout << path[path.size() - K] << endl;
    else
        cout << "-1" << endl;
}

void Path(Node *root, int node, int K, vector<int> &path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    Path(root->right, node, K, path);
    Path(root->left, node, K, path);

    if (root->data == node)
    {
        printNode(path, K + 1);
        return;
    }

    path.pop_back();
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> path;
    int node = 4;
    int K = 2;
    cout << "Node at a distance of " << K << " from " << node << " is : ";
    Path(root, node, K, path);

    return 0;
}
