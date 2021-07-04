/*
Problem Statement:
-----------------
Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be single element also.
Examples: 

Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0
*/

// Link --> https://www.geeksforgeeks.org/maximum-product-subset-array/

// Code: 
#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
    int max_negative = INT_MIN;
    int zeros = 0;
    int negatives = 0;
    int answer = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zeros++;
            continue;
        }

        else if (a[i] < 0)
        {
            negatives++;
            if (a[i] > max_negative)
                max_negative = a[i];
        }
        answer *= a[i];
    }

    // if all the elements are zero.
    if (zeros == n)
        return 0;

    // if there is only one negative number.
    else if (negatives == 1 and zeros == (n - 1))
        return 0;

    // if negative numbers are od then we will remove the maximum negative.
    else if (negatives % 2 != 0)
        answer = answer / max_negative;
    
    return answer;
}

int main()
{
    int a[] = {0 , 0 , -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum Product is : " << maxProductSubset(a, n);
    return 0;
}
