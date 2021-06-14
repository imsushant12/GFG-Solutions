/*
Problem Statement:
------------------
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Example 1:
---------
Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100. InOrder: 30 35 40 80 100.
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40

Example 2:
---------
Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

// Code:
Node* constructTree(int pre[] , int size)
{
    if(canRepresentBST(pre , size) == false)
    {   
        cout<<"NO";
        return NULL;
    }

    Stack* stack = createStack(size);
    Node* root = newNode(pre[0]);

    push(stack , root);

    int i;
    Node* temp;

    for(i=1 ; i<size ; i++)
    {
        temp = NULL;

        while(!isEmpty(stack) && pre[i] > peek(stack)->data)
            temp = pop(stack);
            
        if(temp != NULL)
        {
            temp->right = newNode(pre[i]);
            push(stack , temp->right);
        }

        else
        {
            peek(stack)->left = newNode(pre[i]);
            push(stack , peek(stack)->left);
        }
    }
    return root;
}
