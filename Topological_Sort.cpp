/*
Problem Statement:
-----------------
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices 
and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, 
you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
*/

// Link --> https://practice.geeksforgeeks.org/problems/topological-sort/1

// Code:
class Solution
{
	public: 
	vector<int> topoSort(int v, vector<int> graph[]) 
	{
	    vector<int> answer;
	    vector<int> indegree(v,0);
	    queue<int> q;
	    
	    // Getting indegrees of each vertex.
	    for(int i=0; i<v; i++)
	        for(auto j : graph[i])
	            indegree[j]++;
	   
	    // Pusing all the 0-indegree vertex in graph
	    for(int i=0; i<v; i++)
	        if(indegree[i] == 0)
	            q.push(i);
	            
	    while(!q.empty())
	    {
	        int current = q.front();
	        q.pop();
	        answer.push_back(current);
	        
	        for(auto j : graph[current])
	        {
	            indegree[j]--;
	            if(indegree[j] == 0)
	                q.push(j);
	        }
	    }
	    return answer;
	}
};



