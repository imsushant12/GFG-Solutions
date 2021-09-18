/*
Problem Statement:
------------------
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:
----------
Input:
N=6
knightPos[] = {4, 5}
targetPos[] = {1, 1}
Output: 3

Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), 
the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight 
to reach from its current position to the given target position.
*/

// Link : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

// Code:
class Solution 
{
public:
	int minStepToReachTarget(vector<int>&knight, vector<int>&target, int n)
	{
	    // Taking the positions of knight and target.
	    // knight --> (x1, y1) and target --> (x2,y2)
	    int x1 = knight[0];
	    int y1 = knight[1];
	    int x2 = target[0];
	    int y2 = target[1];
	    
	    // 2-D Array to reprsent maze.
	    int a[1001][1001];
	    
	    for(int i=0 ; i<n ; i++)
	        for(int j=0 ; j<n ; j++)
	            a[i][j] = 0;
	            
	    // Checking if source and destination is same.
	    if(x1 == x2 && y1 == y2)
	        return 0;
	   
	   // BFS to traverse the entire maze.
	   queue <pair<int,int>> q;
	   q.push({x1-1 , y1-1});
	   
	   while(!q.empty())
	   {
	       auto current = q.front();
	       q.pop();
	       
	       // Getting current position in terms of i and j
	       int i = current.first;
	       int j = current.second;
	       
	       if((i+1)>=0 && (i+1)<n && (j+2)>=0 && (j+2)<n && a[i+1][j+2]==0)
	       {
	           a[i+1][j+2] = a[i][j] + 1;
	           q.push({i+1 , j+2});
	       }
	       
	       if((i-1)>=0 && (i-1)<n && (j+2)>=0 && (j+2)<n && a[i-1][j+2]==0)
	       {
	           a[i-1][j+2] = a[i][j] + 1;
	           q.push({i-1 , j+2});
	       }
	       
	       if((i-2)>=0 && (i-2)<n && (j+1)>=0 && (j+1)<n && a[i-2][j+1]==0)
	       {
	           a[i-2][j+1] = a[i][j] + 1;
	           q.push({i-2 , j+1});
	       }
	       
	       if((i+2)>=0 && (i+2)<n && (j+1)>=0 && (j+1)<n && a[i+2][j+1]==0)
	       {
	           a[i+2][j+1] = a[i][j] + 1;
	           q.push({i+2 , j+1});
	       }
	       
	       if((i-1)>=0 && (i-1)<n && (j-2)>=0 && (j-2)<n && a[i-1][j-2]==0)
	       {
	           a[i-1][j-2] = a[i][j] + 1;
	           q.push({i-1 , j-2});
	       }
	       
	       if((i+1)>=0 && (i+1)<n && (j-2)>=0 && (j-2)<n && a[i+1][j-2]==0)
	       {
	           a[i+1][j-2] = a[i][j] + 1;
	           q.push({i+1 , j-2});
	       }
	       
	       if((i-2)>=0 && (i-2)<n && (j-1)>=0 && (j-1)<n && a[i-2][j-1]==0)
	       {
	           a[i-2][j-1] = a[i][j] + 1;
	           q.push({i-2 , j-1});
	       }
	       
	       if((i+2)>=0 && (i+2)<n && (j-1)>=0 && (j-1)<n && a[i+2][j-1]==0)
	       {
	           a[i+2][j-1] = a[i][j] + 1;
	           q.push({i+2 , j-1});
	       }
	   }
	   return a[x2 - 1][y2 - 1];
	}
};
