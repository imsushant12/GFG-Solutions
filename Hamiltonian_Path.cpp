/*
Problem Statement:
------------------
A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. Given an undirected graph the task is to check if a Hamiltonian path 
is present in it or not.

Example 1:
---------
Input:
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
Output:
1 
Explanation: 
There is a hamiltonian path: 1 -> 2 -> 3 -> 4 

Example 2:
---------
Input:
N = 4, M = 3 
Edges[][] = { {1,2}, {2,3}, {2,4} } 
Output: 
0 
Explanation: 
It can be proved that there is no hamiltonian path in the given graph.

Your task:
You don't need to read input or print anything. Your task is to complete the function check() which takes the N( the number of vertices), M (Number of edges) 
and the list of Edges[][] (where Edges[i] denotes the undirected Edge between vertices Edge[i][0] and Edges[i][1] ) as input parameter and returns true (boolean value) 
if the graph contains Hamiltonean path,otherwise returns false. 

Expected Time Complexity: O(N!).
Expected Auxiliary Space: O(N+M).
*/

// Link --> https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1#

// Code:
class Solution
{
    public:
    vector<vector<int>> V;
    bool dfs(int v, int label[15], int count, int N)
    {
    	label[v] = 1;
    	if(count == N)
    	    return true;
    	
    	for(int j=0 ; j<V[v].size() ; j++)
    	{
    		if(label[V[v][j]] == 0)
    		{
    			if(dfs(V[v][j], label, count+1, N))
    			    return true;
    			label[V[v][j]] = 0;
    		}
    	}
    	return false;
    }
 
    bool check(int N, int M, vector<vector<int>> Edges)
    {
        V = vector<vector<int>>(N+1);
        
        for(auto i : Edges)
        {
            V[i[0]].push_back(i[1]);
		    V[i[1]].push_back(i[0]);
        }
        
    	int label[15];
    	
    	for(int i=0 ; i<=N ; i++)
    		label[i] = 0;
    	
    	for(int i=0 ; i<N ; i++)
    	{
    		if(dfs(i, label, 1, N))
    		    return true;
    		label[i] = 0;
    	}
    	return false;
    }
};

/*
// Another Approach:
class Solution
{
    public:
    bool checkUtil(int u, int n, vector<bool> &visited, vector<vector<int>> edges, int &count)
    {
        visited[u] = true;
        count++;
        
        if(count == n)
            return true;
        
        for(auto i : edges[u])
        {
            if(!visited[i])
            {
                bool flag = checkUtil(i, n, visited, edges, count);
                
                if(flag)
                    return true;
            }
            visited[u] = false;
            return false;
        }
    }
    
    bool check(int n, int m, vector<vector<int>> edges)
    {
        vector<bool> visited(n, false);
        
        int count = 0;
        
        bool flag = false;
        
        for(int i=0; i<n; i++)
            if(checkUtil(i, n, visited, edges, count))
                flag = true;
        
        return flag;
    }
};
*/


