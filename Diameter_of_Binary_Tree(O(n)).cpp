/*
Problem Statement:
-----------------
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. 
Example 1:
---------
Input:
       1
     /  \
    2    3
Output: 3
Example 2:
---------
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task: You need to complete the function diameter() that takes root as parameter and returns the diameter.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/

// Link --> https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

// Code : 
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

pair <int,int> utilityDia(struct node* root)
{
    pair <int , int> p,lt,rt,answer;

    // first --> height
    // second --> diameter

    if(root == NULL)
    {
        p.first = -1;
        p.second = 0;
        return p;
    }

    lt = utilityDia(root->left);
    rt = utilityDia(root->right);

    //storing resultant height.
    answer.first = max(lt.first , rt.first) + 1;

    // passing through root
    int dia = lt.first + rt.first + 2;

    answer.second = max(dia, max(lt.second , rt.second));

    return answer;
}

int diameter(struct node* root)
{
    return (utilityDia(root).second + 1);
}
