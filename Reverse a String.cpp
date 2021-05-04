/*
Problem Statement:
-------------------
You are given a string str. You need to reverse the string.
  
Example 1:
Input:
str = Geeks
Output: skeeG

Example 2:
Input:
str = for
Output: rof
*/

//Link --> https://practice.geeksforgeeks.org/problems/reverse-a-string/1#

//Code:
string reverseWord(string str)
{
    int n = str.length();
    for(int i=0 ; i<n/2 ; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp; 
    }
    return str;
}
