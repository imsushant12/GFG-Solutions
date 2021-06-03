/*
Problem Statement:
-----------------
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. 
It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis 
contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Example-1: 
---------
Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains left subtree and second one contains the right subtree. Preorder of above tree is "1 2 3".  

Example-1: 
---------
Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
*/

// Link --> https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int index = 0;
Node* treeFromString(string s)
{
    if(s.size() == 0 or index >= s.size())
        return NULL;

    // Since root number or any number may be greater than
    // 9. So, we must consider whole number. Hence, we will
    // run a loop to get whole number.
    int number = 0;
    while(s[index] != '(' and s[index] != ')' and index < s.size())
    {
        int digit = (int)(s[index] - '0');
        number = number * 10 + digit;
        index++;
    }

    // creating node with the number formed.
    Node *root = newNode(number);

    // termination condition
    if(index >= s.size())
        return root;

    // constructing left sub-tree.
    if(s[index] == '(')
    {
        index++;
        root->left = treeFromString(s);
    }

    if(s[index] == ')')
    {
        index++;
        return root;
    }

    // constructing right sub-tree.
    if(s[index] == '(')
    {
        index++;
        root->right = treeFromString(s);
    }
    if(s[index] == ')' )
    {
        index++;
        return root;
    }

    return root;
}


int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str);
    preOrder(root);
}

/*
Time complexity = O(N)
Space Complexity = O(1)
*/
