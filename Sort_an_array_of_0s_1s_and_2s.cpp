/*
Problem Statement:
-----------------
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:
---------
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Example 2:
---------
Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task: You don't need to read input or print anything. Your task is to complete the function sort012() that takes 
an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

// Code:
class Solution
{
    public:
    void sort012(int a[], int n)
    {
         int m=0 ,l=0 , h=n-1;
         
         while(m <= h)
         {
            if(a[m] == 0)
            {
                swap(a[l] , a[m]);
                l++;
                m++;
            }
             
            else if(a[m] == 2)
            {
                swap(a[m] , a[h]);
                h--;
            }
            
            else
                m++;
         }
    }
    
};
