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

void postorder(struct node* root)
{
    if(root == NULL)
        return;

    stack <node*> s1,s2;
    struct node *temp;

    s1.push(root);
    while(!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        temp = s2.top();
        s2.pop();
        cout<<temp->data<<"  ";
    }
}

/*
// Recursive Way:
void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
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

    cout<<"Post-order traversal is  : ";
    postorder(root);

    return 0;
}

