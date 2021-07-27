/*
Problem Statement:
------------------
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram will be 8  and there will be 2 consecutive histogram. And hence the area of the histogram will be 8x2 = 16.

Your Task: The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible 
and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

// Code:
class Solution
{
public:
    long long getMaxArea(long long hist[] , long long n)
    {
        stack<long long> s; 
  
        long long max_area = 0;  
        long long tp;  
        long long area_with_top; 
      
        long long i = 0; 
        
        while (i < n) 
        { 
            if (s.empty() || hist[s.top()] <= hist[i]) 
                s.push(i++); 
     
            else
            { 
                tp = s.top();  
                s.pop();  
                area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 
       
                if (max_area < area_with_top) 
                    max_area = area_with_top; 
            } 
        } 
      
        while (!s.empty()) 
        { 
            tp = s.top(); 
            s.pop(); 
            
            area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 
      
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
        return max_area;
    }
};
