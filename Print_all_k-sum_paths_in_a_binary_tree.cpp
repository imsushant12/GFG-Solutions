/*
Problem Statement:
------------------
A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k.
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

Examples:
---------
Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
*/

// Link --> https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

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

void printPath(vector<int> &path , int start)
{
    for (int i = start; i < path.size(); i++)
    {
        cout << path[i] << "  ";
    }
    cout << endl;
}

void sumPath(Node *root, int K, vector<int> &path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);
    
    sumPath(root->right, K, path);
    sumPath(root->left, K, path);

    int sum = 0;
    for (int i = path.size()-1; i>=0 ;  i--)
    {
        sum += path[i];
        if (sum == K)
            printPath(path , i);
    }

    path.pop_back();
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    vector<int> path;
    int sum = 5;
    cout << "Sum paths are : \n";
    sumPath(root, sum, path);

    return 0;
}
