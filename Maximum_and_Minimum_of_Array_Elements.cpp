/*
Problem Statement:
-----------------
Given an array A[ ], find maximum and minimum elements from the array.

Input:
The first line of input contains an integer T, denoting the number of testcases. The description of T testcases follows. The first line of each testcase contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase in a new line, print the maximum and minimum element in a single line with space in between.

Constraints:
1 ≤ T ≤ 30
1 ≤ N ≤ 100
0 ≤A[i]<100

Example:
Input:
2
4
5 4 2 1
1
8

Output:
5 1
8 8
 */

// Link --> https://practice.geeksforgeeks.org/problems/maximum-and-minimum-of-array-elements/0#

// Code:
#include<iostream>
using namespace std;

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i=0 ; i<n ; i++)
	        cin>>a[i];
	    
	    int min = a[0] , max = a[0];  
	    for(int i=0 ; i<n ; i++)
	    {
	        if(a[i] > max)
	            max = a[i];
	        else if(a[i] < min)
	        min = a[i];
	    }
	    cout<<max<<" "<<min<<endl;
	}
	return 0;
}
