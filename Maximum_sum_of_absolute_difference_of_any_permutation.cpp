/*
Problem Statement:
------------------
Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.
Examples: 
---------
Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18
*/

// Link --> https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

// Code: 
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
    vector<int> v;
    sort(a, a + n);

    int sum = 0;

    // Alternatively inserting smallest and largest element 
    // to vector to get a zig-zag kind of array.
    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(a[i]);
        v.push_back(a[n - i - 1]);
    }

    // if number of elements are odd then inserting middle element.
    if(n %2 != 0)
        v.push_back(a[n/2]);

    for(int i=0 ; i<n ; i++)
    {
        if(i == n-1)
            sum += (abs(v[i] - v[0]));
        else
            sum += (abs(v[i] - v[i+1]));
    }

    return sum;
}

int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Maximum sum of absolute difference of any permutation is : " << MaxSumDifference(a, n);
}
