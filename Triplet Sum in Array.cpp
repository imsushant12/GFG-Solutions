/*
Problem Statement:
-----------------
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:
---------
Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation: The triplet {1, 4, 8} in the array sums up to 13.

Example 2:
---------
Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation: The triplet {1, 3, 6} in the array sums up to 10.

Your Task: You don't need to read input or print anything. Your task is to complete the function find3Numbers() 
which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet 
in the array arr[] which sums up to X and False otherwise.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

// Code:
class Solution
{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[] , int n , int X)
    {
        bool answer = false;
        
        sort(a , a+n);
        
        for(int i=0 ; i<n-2 ; i++)
        {
            int start = i+1;
            int end = n-1;
            while(start < end)
            {
                int temp = a[start] + a[end];
                if(temp + a[i] == X)
                {
                    answer = true;
                    break;
                }
                
                else if(temp > X-a[i])
                    end--;
        
                else
                   start++;
            }
        }
        return answer;
    }

};
