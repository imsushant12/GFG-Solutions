/*
Problem Statement:
-----------------
Given a string S, check if it is palindrome or not.

Example 1:
---------
Input: S = "abba"
Output: 1
Explanation: S is a palindrome.

Example 2:
---------
Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome.

Your Task: You don't need to read input or print anything. Complete the function isPlaindrome() which accepts string S and returns a boolean value

Expected Time Complexity: O(Length of S) 
Expected Auxiliary Space: O(1) 
*/

// Link --> https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#

// Code:
class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int n= S.size();
	    
	    for(int i=0 ; i<n/2 ; i++)
	       if(S[i] != S[n-i-1])
	           return 0;
	 
	    return 1;
	}

};
