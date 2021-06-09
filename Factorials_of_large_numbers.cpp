/*
Problem Statement:
-----------------
Given an integer N, find its factorial.

Example 1:
---------
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:
----------
Input: N = 10
Output: 3628800
Explanation : 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task: You don't need to read input or print anything. Complete the function factorial() that takes integer N 
as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

// Code:
class Solution 
{
public:
    void multiply(int x , vector <int> &result)
    {
        int carry = 0;  
     
        for(int i=0 ; i<result.size() ; i++)
        {
            int prod = result[i] * x + carry;

            result[i] = prod % 10; 

            carry  = prod/10;   
        }

        while(carry)
        {
            result.push_back(carry % 10);
            carry = carry/10;
        }
    }
    
    vector <int> factorial(int N)
    {
        vector <int> answer;
        
        answer.push_back(1);
        int size = 1;
 
        for(int i=2 ; i <= N ; i++)
            multiply(i , answer);
        
        reverse(answer.begin() , answer.end());
        
        return answer;
    }
};
