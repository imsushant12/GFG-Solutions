/*
Problem Statement:
-----------------
Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which 
returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:
---------
Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at node 9.  

Input: The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. 
Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . 
Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

Output: The output for each test case will be 1 if the BST contains a dead end else 0.
*/

// Link --> https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

// Code:
void isDeadUtil(Node* root , int l , int h , bool &answer)
{
    if(root == NULL)
        return;
    
    if(answer)
        return;
        
    if(root->left == NULL and root->right == NULL)
    {
        if(l == h)
            answer = true;
        return;
    }
    isDeadUtil(root->left , l , root->data-1 , answer);
    isDeadUtil(root->right , root->data+1 , h , answer);
}

bool isDeadEnd(Node *root)
{
    bool answer = false;
    isDeadUtil(root , 1 , INT_MAX , answer);
    
    return answer;
}
