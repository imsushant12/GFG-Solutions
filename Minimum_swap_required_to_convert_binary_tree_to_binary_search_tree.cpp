/*
Problem Statement:
-----------------
Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Examples:  
---------
Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:
       5
     /   \
    6     7
  /  \   /  \
 8    9 10  11
 
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
       8
     /   \
    6     10
  /  \   /  \
 5    7 9   11
*/

// Link --> https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/

// Code:
#include<bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v, int n, int index)
{
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);

    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v)
{
    vector <pair <int , int>> result(v.size());

    int counter = 0;
    for(int i = 0; i < v.size(); i++)
    {
        result[i].first = v[i];
        result[i].second = i;
    }

    sort(result.begin() , result.end());
    for(int i=0 ; i < result.size() ; i++)
    {
        if(i == result[i].second)
            continue;
        else
        {
            swap(result[i].first , result[result[i].second].first);
            swap(result[i].second , result[result[i].second].second);
        }

        if(i != result[i].second)
            i--;

        counter++;
    }
    return counter;
}

int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);

    cout<<"Minimum swaps needed = "<<minSwaps(v);

    return 0;
}


