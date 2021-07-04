/*
Problem Statement:
-----------------
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character 
with the second character and replace all the occurences of the second character with the first character. 
Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
---------
Input:
A = "ccad"
Output: "aacd"
Explanation: In ccad, we choose ‘a’ and ‘c’ and after doing the replacement operation once we get, aacd and this is the lexicographically smallest string possible. 

Example 2:
----------
Input:
A = "abba"
Output: "abba"
Explanation: In abba, we can get baab after doing the replacement operation once for ‘a’ and ‘b’ but that is not lexicographically smaller than abba. So, the answer is abba. 

Your Task: You don't need to read input or print anything. Your task is to complete the function chooseandswap() which takes the string A as input parameters 
and returns the lexicographically smallest string that is possible after doing the operation at most once.

Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#

// Code:
class Solution
{
public:
    string chooseandswap(string a)
    {
        set <char> s;
        for(int i=0 ; i<a.length() ; i++)
            s.insert(a[i]);
        
        for(int i=0 ; i<a.length() ; i++)
        {
            // first removing the current character 
            // then checking the rest set to get smallest character(first)
            s.erase(a[i]);
            
            if(s.empty())
                break;
            
            char first = *s.begin();
            if(first < a[i])
            {
                char second = a[i];
                
                // swapping first and second character.
                for(int j=0 ; j<a.length() ; j++)
                {
                    if(a[j] == first)
                        a[j] = second;
                    else if(a[j] == second)
                        a[j] = first;
                }
                break;
            }
        }
        return a;
    }
    
};
