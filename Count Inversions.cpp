/*
Problem Statement:
-----------------
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:
---------
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
---------
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Example 3:
---------
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Your Task: You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] 
and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
*/

// Link --> https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

// Code:
class Solution
{
  public:
    long long int count = 0;
    void merge(long long a[] , long long p , long long q , long long r)
    {
        long long l = q-p+1;
        
        long long a1[l];
    
        long long l2 = r-q;
        
        long long a2[l2];
        
        for(long long i=0 ; i<l ; i++)
            a1[i] = a[i+p];
  
        for(long long i=0 ; i<l2 ; i++)
            a2[i] = a[q+i+1];

        
        long long left=0 , right=0 , k=p;
        
        while(left < l && right < l2)
        {
            if(a1[left] <= a2[right])
            {
                a[k] = a1[left];
                left++;
            }
            
            else
            {
                a[k] = a2[right];
                right++;
                count += (l-left); 
            }
            
            k++;
        }
        
        while(left < l)
            a[k++] = a1[left++];
    }
  
    void mergeLogic(long long a[] , long long l , long long r)
    {
        if(l >= r)
        {
            return;
        }
        int mid = l + (r-l)/2;
        mergeLogic(a,l,mid);
        mergeLogic(a,mid+1,r);
        merge(a,l,mid,r);
    }
    long long int inversionCount(long long a[] , long long n)
    {
        mergeLogic(a , 0 , n-1);
        return count;
    }

};
