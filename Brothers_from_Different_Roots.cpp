/*
Problem Statement:
-----------------
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), 
that returns the count of all pairs from both the BSTs whose sum is equal to x.

Examples:
---------
Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are: (5, 11), (6, 10) and (8, 8)

Input: The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, then reference pointer to the root(root2) of the BST2 
and last the element X. There will be T test cases and for each test case the function will be called separately.

Output: For each test cases print the required number of pairs on new line.
*/

// Link --> https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#

// Code:
vector <int> v1;
void inorder(Node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    v1.push_back(root->data);
    inorder(root->right);
}

vector <int> v2;
void inorder2(Node *root)
{
    if(root == NULL)
        return;
    
    inorder2(root->left);
    v2.push_back(root->data);
    inorder2(root->right);
}

int countPairs(Node* root1 , Node* root2 , int x)
{
    int counter = 0;
    v1.clear();
    v2.clear();
    inorder(root1);
    inorder2(root2);
    
    int i = 0;
    int j = v2.size()-1;
    while(i < v1.size() and j >= 0)
    {
        if(v1[i] + v2[j] == x)
        {
            counter++;
            j--;
        }
        else if(v1[i] + v2[j] < x)
            i++;
        else
            j--;
    }
    return counter;
}
