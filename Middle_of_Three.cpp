/*
Problem Statement:
-----------------
Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

Example 1:
---------
Input:
A = 978, B = 518, C = 300
Output:
518
Explanation: Since 518>300 and 518<978, so 518 is the middle element.

Example 2:
---------
Input:
A = 162, B = 934, C = 200
Output:
200
Exaplanation: Since 200>162 && 200<934, So, 200 is the middle element.

Your Task: You don't need to read input or print anything.Your task is to complete the function middle() which takes three integers A,B and C 
as input parameters and returns the number which has middle value.

Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#

// Code:
class Solution{
  public:
    int middle(int a , int b , int c)
    {
        if(a<b && a>c || a>b && a<c)
            return a;
        else if(b>a && b<c || b>c && b<a)
            return b;
        else
            return c;
    }
};
