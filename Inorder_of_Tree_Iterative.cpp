#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void inorder(struct node* root)
{
    stack <node*> s;
    struct node *temp = root;

    while(temp != NULL || !s.empty())
    {
        while(temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        cout<<temp->data<<"  ";

        temp = temp->right;
    }
}

/*
// Recursive Way:
void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}
*/

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left ->left = newNode(7);
    root->right->left ->right = newNode(8);

    cout<<"In-order traversal is  : ";
    inorder(root);

    return 0;
}
