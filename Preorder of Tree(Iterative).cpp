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

void preorder(struct node* root)
{
      stack <node*> s;
      struct node *temp = root;

      while(temp!= NULL || !s.empty())
      {
          while(temp)
          {
              cout<<temp->data<<"  ";
              s.push(temp);
              temp = temp->left;
          }

          temp = s.top();
          s.pop();

          temp = temp->right;
      }
}

/*
// Recursive Way:
void preorder(struct node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
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

    cout<<"Pre-order traversal is  : ";
    preorder(root);
    return 0;
}

