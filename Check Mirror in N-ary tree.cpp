/*
Problem Statement:
------------------
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, 
and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

Example 1:
----------
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1

Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree is mirror image of the first.

Example 2:
---------
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
1

Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree isn't mirror image of the first. 

Your Task: You don't need to read input or print anything. Your task is to complete the function checkMirrorTree() which takes 2 Integers 
n, and e;  and two arrays A[] and B[] of size 2*e as input and returns 1 if the trees are mirror images of each other and 0 if not.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

// Link --> https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#

// Code:
class Solution 
{
  public:
    int checkMirrorTree(int n , int e , int A[] , int B[]) 
    {
        vector<int> g1[100005];
		vector<int> g2[100005];
		
		for(int i=0; i<2*e; i+=2)
		{
			int x = A[i];
			int y = A[i+1];
			g1[x].push_back(y);
		}
		
		for(int i=0 ; i<2*e ; i+=2)
		{
			int x = B[i];
			int y = B[i+1];
			g2[x].push_back(y);
		}
		
		stack<int> s;
		queue<int> q;
		
		s.push(1);
		q.push(1);
		bool f=0;
		while(!s.empty() and !q.empty())
		{
			int s1 = s.top();
			s.pop();
			int s2 = q.front();
			q.pop();
			
			if(s1!=s2)
			{
				f=1;
				break;
			}
			
			for(auto i = 0 ; i<g1[s1].size() ; i++)
				s.push(g1[s1][i]);
				
			vector<int> k;
			
			while(!q.empty())
			{
    			k.push_back(q.front());
    			q.pop();
			}
			
			for(auto i=0 ; i<g2[s2].size() ; i++)
				q.push(g2[s2][i]);
				
			for(int i=0 ; i<k.size() ; i++)
			    q.push(k[i]);
		}
		
		if(s.empty() and q.empty() and !f)
			return 1;
		else 
		    return 0;
    }
};
