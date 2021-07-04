/*
Problem Statement:
-----------------
Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, 
each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 
Example 1:
---------
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non repeating character is as follow-
              "a" - first non-repeating character is 'a'
              "aa" - no non-repeating character so '#'
              "aab" - first non-repeating character is 'b'
              "aabc" - first non-repeating character is 'b'

Example 2:
---------
Input: A = "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow-
              "z" - first non-repeating character is 'z'
              "zz" - no non-repeating character so '#'
 
Your Task: You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and 
returns a string after processing the input stream.
 
Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26)
*/

// Link --> https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// Code:
class Solution 
{
	public:
		string FirstNonRepeating(string s)
		{
		    vector <int> vec(26,0);
		    string answer = "";
		    int n = s.length();
		    vector <char> v;
		    
		    for(int i=0 ; i<n ; i++)
		    {
		        if(!vec[s[i] - 'a'])
		            v.push_back(s[i]);
		    
		        vec[s[i] - 'a']++;
		        int f=0, m=v.size();
		    
    		    for(int i=0 ; i<m ; i++)
    		    {
    		        if(vec[v[i] - 'a'] == 1)
    		        {
    		            answer.push_back(v[i]);
    		            f = 1;
    		            break;
    		        }
    		    }
    		    
    		    if(f == 0)
    		        answer.push_back('#');
		    }
		        
		    return answer;
		}

};
