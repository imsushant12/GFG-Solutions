/*
Problem Statement:
------------------
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph 
contains negative weight cycle otherwise returns 0.

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
*/

// Link --> https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

// Code: 
class Solution
{
    public int isNegativeWeightCycle(int n, int[][] edges)
    {
        int[] d = new int[n];
        int[] p = new int[n];
        
        Arrays.fill(d, 0);
        Arrays.fill(p, -1);
        
        int x = -1;
        
        for(int i=0; i<n; i++)
        {
            x = -1;
            for(int j = 0; j<edges.length; j++)
            {
                if(d[edges[j][0]] + edges[j][2] < d[edges[j][1]])
                {
                    d[edges[j][1]] = d[edges[j][0]] + edges[j][2];
                    p[edges[j][1]] = edges[j][0];
                    x = edges[j][1];
                }
            }
        }
        if(x == -1)
            return 0;
        else
            return 1;
    }
}
