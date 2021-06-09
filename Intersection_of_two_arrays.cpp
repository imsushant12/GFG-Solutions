/*
Problem Statement:
-----------------
Given two arrays a[] and b[] respectively of size n and m, the task is to print the count of elements in the intersection (or common elements) of the two arrays.

For this question, the intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Example 1:
----------
Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}
Output: 1
Explanation: 89 is the only element in the intersection of two arrays.

Example 2:
---------
Input:
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 6}
b[] = {3, 4, 5, 6, 7} 
Output: 4
Explanation: 3 4 5 and 6 are the elements in the intersection of two arrays.

Your Task: You don't need to read input or print anything. Your task is to complete the function NumberofElementsInIntersection() 
which takes two integers n and m and their respective arrays a[] and b[]  as input. The function should return the count of the number of elements in the intersection.

Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(min(n,m)).
*/

// Link --> https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#

// Code:
class Solution
{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[] , int b[] , int n, int m)
    {
        unordered_set <int> s;
        int count = 0;
        for(int i=0; i<n; i++)
            s.insert(a[i]);
        
        for(int i=0; i<m; i++)
        {
            if(s.find(b[i]) != s.end())
            {
                s.erase(b[i]);
                count++;
            }
        }
        return count;
    }
};
