/*
Problem Statement:
-----------------
Given a string S with repeated characters (only lowercase). The task is torearrange characters in a string such that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.

Input: The first line of input contains an integer T denoting the number of test cases. ThenT test cases follow. 
Each test case contains a single line containing a string oflowercase english alphabets.
Output: For each test case in a new line print "1" (without quotes) if the generated stringdoesn't contains any same adjacent characters, 
else if no such string is possible tobe made print "0" (without quotes).
Constraints:
1 <= T <= 100
1 <= length of string <= 10
Example:
-------
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb
Output:
1
1
0
Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged sothat no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that thereshould not be any adjacent repeated character.
*/

// Link --> https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems

// Code:

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
struct Key
{
	int freq;
	char ch;
	bool operator<(const Key &k) const
	{
		return freq < k.freq;
	}
};

string rearrangeString(string str)
{
	int n = str.length();
	int count[MAX_CHAR] = {0};
	
	for (int i = 0 ; i < n ; i++)
		count[str[i]-'a']++;
		
	priority_queue< Key > pq;
	
	for (char c = 'a' ; c <= 'z' ; c++)
		if (count[c-'a'])
			pq.push( Key { count[c-'a'], c} );
			
	str = "" ;
	Key prev {-1, '#'} ;
	
	while (!pq.empty())
	{
		Key k = pq.top();
		pq.pop();
		
		str = str + k.ch;
		
		if (prev.freq > 0)
			pq.push(prev);
			
		(k.freq)--;
		
		prev = k;
	}
	
	if (n != str.length())
		return "-1";
	else
		return str;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    str = rearrangeString(str);
    	int flag = 1;
    	if(str != "-1")
    	{
        	for(int i=0 ; i<str.length() ; i++)
        	{
        		if(i > 0)
        		    if(str[i-1] == str[i])
        			    flag = 0;
        	}
    	    if(flag == 1)
    		    cout << "1\n";
    	    else
    	        cout << "0\n";
    	}
	    else
		    cout << "0\n";
	}
    return 0;
}
