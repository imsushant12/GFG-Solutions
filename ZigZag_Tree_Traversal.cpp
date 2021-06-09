/*
Problem Statement:
-----------------
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
---------
Input:
        3
      /   \
     2     1
     
Output: 3 1 2

Example 2:
---------
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
  
Output: 7 7 9 8 8 6 9 10 
 

Your Task: You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes 
the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#

// Code:
vector <int> zigZagTraversal(Node* root)
{
	vector <int> res;

	stack <Node*> s1 , s2;

	s1.push(root);
	bool flag = true;
	
	while(!s1.empty())
	{
		Node* temp = s1.top();
		s1.pop();
		
		if(temp) 
		{
			res.push_back(temp->data);
			
			if(flag == true)
			{
				if(temp->left)
					s2.push(temp->left);
				if(temp->right)
					s2.push(temp->right);
			}
			else 
			{
				if(temp->right)
					s2.push(temp->right);
				if(temp->left)
					s2.push(temp->left);
			}
		}
		
		if(s1.empty()) 
		{
			flag = !flag;
			swap(s1 , s2);
		}
	}
	return res;
}
