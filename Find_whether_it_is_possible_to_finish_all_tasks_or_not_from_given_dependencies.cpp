/*
Problem Statement:
-----------------
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, 
which is expressed as a pair: [0, 1]
Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?

Examples:
--------
Input: 2, [[1, 0]] 
Output: true 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.

Input: 2, [[1, 0], [0, 1]] 
Output: false 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.

Input: 3, [[1, 0], [2, 1], [3, 2]] 
Output: true 
Explanation: There are a total of 3 tasks to pick. To pick tasks 1 you should have finished task 0, and to pick task 2 you should have finished task 1 and 
to pick task 3 you should have finished task 2. So it is possible.
*/

// Link --> https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

// Code:
#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> make_graph(int totalTasks, vector<pair<int, int>> &tasks)
{
    vector<unordered_set<int>> graph(totalTasks);
    for (auto x : tasks)
        graph[x.second].insert(x.first);

    return graph;
}

bool dfs(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
    if (visited[node])
        return false;

    onpath[node] = visited[node] = true;

    for (int neigh : graph[node])
        if (onpath[neigh] || dfs(graph, neigh, onpath, visited))
            return true;

    return onpath[node] = false;
}

bool canFinish(int totalTasks, vector<pair<int, int>> &tasks)
{
    vector<unordered_set<int>> graph = make_graph(totalTasks, tasks);
    vector<bool> onpath(totalTasks, false);
    vector<bool> visited(totalTasks, false);

    for (int i = 0; i < totalTasks; i++)
        if (!visited[i] && dfs(graph, i, onpath, visited))
            return false;

    return true;
}

int main()
{
    int totalTasks = 4;

    vector<pair<int, int>> tasks;

    tasks.push_back({1, 0});
    tasks.push_back({2, 1});
    tasks.push_back({3, 2});

    if (canFinish(totalTasks, tasks))
        cout << "Possible to finish all tasks";
    else
        cout << "Impossible to finish all tasks";

    return 0;
}
