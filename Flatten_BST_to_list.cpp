/*
Problem Statement:
------------------
Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes 
at its right, and its left node must be NULL after flattening. We must do it in O(H) extra space where ‘H’ is the height of BST.

Examples:
--------
Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8
Input:
      1
       \
        2
         \
          3
           \
            4
             \
              5
Output: 1 2 3 4 5
*/

// Link --> https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/?web=1&wdLOR=cC00AC783-F071-4AE9-BEEB-186B13B6945B

// Code:
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printList(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << "  ";
        curr = curr->right;
    }
}

void flaten(Node *root)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
        return;

    // Flatening the left subtree
    if (root->left != NULL)
    {
        flaten(root->left);
        // Storing the right subtree in a temporary variable.
        Node *rightSubTree = root->right;

        // Now root's right will be left subtree.
        root->right = root->left;

        // Finally making root's left as NULL. (It wont point anything to its left.
        root->left = NULL;

        // Now calculating the new right of root so that we can attach our original
        // right subtree to the its right.
        Node *temp = root->right;
        while (temp->right != NULL)
            temp = temp->right;

        // Finally attaching as stated above.
        temp->right = rightSubTree;
    }
    // Flatening the right subtree
    flaten(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Flaten Binary Tree as singly linked list : ";
    flaten(root);
    printList(root);
 
    return 0;
}
