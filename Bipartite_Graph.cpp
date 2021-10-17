/*
Problem Statement:
------------------

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 
Expected Time Complexity: O(V)
Expected Space Complexity: O(V)
*/

// Link --> https://practice.geeksforgeeks.org/problems/bipartite-graph/1#

// Code:
class Solution 
{
public:
	bool isBipartite(int V, vector<int>graph[])
	{
	    vector<int> color(V, -1);
        queue<int> q;
        bool is_Bipratite = true;
        for (int i = 0; i < V; i++)
        {
        	if (color[i] == -1)
        	{
        		q.push(i);
        		color[i] = 0;
        		while (!q.empty())
        		{
        			int u = q.front();
        			q.pop();
        			for (auto v : graph[u])
        			{
        				if (color[v] == -1)
        				{
        					color[v] = color[u] ^ 1;
        					q.push(v);
        				}
        				else
        					is_Bipratite = is_Bipratite & (color[u] != color[v]);
        			}
        		}
        	}
        }
        return is_Bipratite;
	}
};
