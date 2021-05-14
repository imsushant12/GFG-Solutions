/*
Problem Statement:
-----------------
Given strings str1 and str2. The task is to find that if str1 is substring in shuffled form of str2 or not. 
Print “YES” if str1 is substring in shuffled form of str2 else print “NO”. 

Examples:
--------

Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld” 
Output: YES 
Explanation: str1 is substring in shuffled form of str2 as 
str2 = “hello” + “fourtwoone” + “world” 
str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form) 
Hence str1 is a substring of str2 in shuffled form.

Input: str1 = “roseyellow”, str2 = “yellow” 
Output: NO 
Explanation: As length of str1 is greater than str2. Hence str1 is not a substring of str2.
*/

// Link --> https://www.geeksforgeeks.org/check-if-the-given-string-is-shuffled-substring-of-another-string/

// Code:
#include <bits/stdc++.h>
using namespace std;

int shuffleSubString(string s1 , string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    if(l1 > l2)
        return 0;

    else
    {
        int freq_s2 [26] = {0};

        for(int i=0 ; i<l2 ; i++)
            freq_s2[ s2[i]-97 ]++;

        bool flag = true;

        for(int i=0 ; i<l1 ; i++)
        {
            if( freq_s2[ s1[i]-97 ] == 0)
            {
                flag = false;
                break;
            }

            else
                freq_s2[ s1[i]-97 ]--;

        }

        if(flag == true)
            return 1;
        else
            return 0;
    }
}


int main()
{
    string s1,s2,res;

    cout<<"Enter the first string : ";
    cin>>s1;

    cout<<"Enter the second string : ";
    cin>>s2;

    if(shuffleSubString(s1 , s2))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

