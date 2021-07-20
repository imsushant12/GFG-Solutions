/*
Problem Statement:
------------------
Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. 
Stacks are represented as an array, and the first index of the array represent the top element of the stack.

Examples: 
---------
Input : stack1[] = { 3, 10}
        stack2[] = { 4, 5 }
        stack3[] = { 2, 1 }
Output : 0
Sum can only be equal after removing all elements from all stacks.
*/

// Link --> https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

// Code:
#include <bits/stdc++.h>
using namespace std;

int maxSum(int s1[], int s2[], int s3[], int n1, int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int top1 = 0, top2 = 0, top3 = 0;
    int answer = 0;

    for (int i = 0; i < n1; i++)
        sum1 += s1[i];
    for (int i = 0; i < n2; i++)
        sum2 += s2[i];
    for (int i = 0; i < n3; i++)
        sum3 += s3[i];

    while (true)
    {
        // The condition when we have not find any sum.
        if (top1 == n1 || top2 == n2 || top3 == n3)
        {
            answer = 0;
            break;
        }

        else if (sum1 == sum2 and sum2 == sum3)
        {
            answer = sum1;
            break;
        }

        // The condition when sum1 is largest, then
        // subtract its top from the sum and shift the top
        else if (sum1 >= sum2 and sum1 >= sum3)
            sum1 -= s1[top1++];

        // The condition when sum2 is largest
        else if (sum2 >= sum3 and sum2 >= sum1)
            sum2 -= s2[top2++];

        // The condition when sum3 is largest
        else if (sum3 >= sum1 and sum3 >= sum2)
            sum3 -= s3[top3++];
    }
    return answer;
}

int main()
{
    int s1[] = {3, 2, 1, 1, 1};
    int s2[] = {4, 3, 2};
    int s3[] = {1, 1, 4, 1};

    int n1 = sizeof(s1) / sizeof(s1[0]);
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int n3 = sizeof(s3) / sizeof(s3[0]);

    cout << "Maximum sum possible is : " << maxSum(s1, s2, s3, n1, n2, n3) << endl;

    return 0;
}
