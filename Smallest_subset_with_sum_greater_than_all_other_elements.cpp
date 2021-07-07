/*
Problem Statement:
-----------------
Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.

Examples : 
----------
Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of this subset is greater than all other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not enough. We can pick elements with values 1, 2 or 2, 2. In any case, the minimum count is 2.
*/

// Link --> https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/

// Code:
#include <bits/stdc++.h>
using namespace std;

int minElements(int a[], int n)
{
    int sum = 0;
    int current_sum = 0;
    int counter = 1;
    sort(a, a + n);

    // calculating the total sum of the elements.
    for (int i = 0; i < n; i++)
        sum += a[i];

    for (int i = n - 1; i > 0; i++)
    {
        current_sum += a[i];
        if ((sum - a[i]) > current_sum)
        {
            counter++;
            sum -= (sum - a[i]);
        }
        else
            break;
    }

    return counter;
}

int main()
{
    int a[] = {8, 9, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum elements needed to make sum greater than rest elements : " << minElements(a, n) << endl;
    return 0;
}
