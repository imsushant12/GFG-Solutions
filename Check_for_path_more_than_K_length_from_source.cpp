/*
Problem Statement:
-----------------
Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending 
at any other vertex such that the distance from source to that vertex is atleast ‘k’ length.

Example:
-------
Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple path has distance 61 (0 -> 7 -> 1-> 2  -> 3 -> 4 -> 5-> 6 -> 8, so output should be false for any input greater than 61.
*/

// Link --> https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/

// Code:
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list<pair<int, int>> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<iPair>[V];
    }

    void addEdge(int u, int v, int w)
    {

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    bool findPath(int source, int k, vector<bool> &visited)
    {
        visited[source] = true;

        if (k == 0)
            return true;

        for (auto i : graph[source])
        {
            int u = i.first;
            int weight = i.second;

            // if the current node is already visited, then there is loop in this path. So continue to next path.
            if(visited[u])
                continue;

            // current weight is itself greater than K-value then this path is the answer.
            if (weight >= k)
                return true;
                
            // if we haven't got our answer, we will make dfs-call but the current K-value 
            // will be k - (sum of path till now) which is (k - weight)
            if (findPath(u, k - weight, visited))
                return true;
        }
        // Backtracking:
        visited[source] = false;
        return false;
    }

    bool pathMoreThanK(int source, int k)
    {
        vector<bool> visited(V, false);

        return findPath(source, k, visited);
    }
};

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int source = 0;
    int k = 62;
    g.pathMoreThanK(source, k) ? cout << "Yes\n" : cout << "No\n";

    k = 60;
    g.pathMoreThanK(source, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
