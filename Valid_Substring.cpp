/*
Problem Statement:
------------------
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:
----------
Input: S = "(()("
Output: 2
Explanation: The longest valid substring is "()". Length = 2.

Example 2:
----------
Input: S = "()(())("
Output: 6
Explanation: The longest valid substring is "()(())". Length = 6.

Your Task: You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  
*/

// Link --> https://practice.geeksforgeeks.org/problems/valid-substring0624/1

// Code:
class Solution 
{
  public:
    int findMaxLen(string s) 
    {
        int start = 0, end = 0 , answer = 0;
        
        for (int i=0 ; i<s.size() ; i++)
        {
            if (s[i] == '(')
                start++;
                
            else
                end++;
                
            if(start == end)
                answer = max(answer , (start + end));
            
            else if(end > start)
                start = end = 0;
        }
        
        start = end = 0;
        
        for (int i=s.size() - 1 ; i>=0 ; i--)
        {
            if (s[i] == '(')
                start++;
                
            else
                end++;
                
            if(start == end)
                answer = max(answer , (start + end));
            
            else if(start > end)
                start = end = 0;
        }
        
        return answer;
    }
};
