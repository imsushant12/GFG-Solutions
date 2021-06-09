/*
Problem Statement:
-----------------
Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 
Note: The output could be large take modulo 109+7.

Input: The first line of input contains an integer T denoting the number of test cases. Then T test cases follow, the first line of each test case contains an integer N 
denoting the size of the first linked list (L1). In the next line are the space separated values of the first linked list. The third line of each test case contains 
an integer M denoting the size of the second linked list (L2). In the forth line are space separated values of the second linked list.

Output: For each test case output will be an integer denoting the product of the two linked list.

User Task: The task is to complete the function multiplyTwoLists() which should multiply the given two linked lists and return the result.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
-------
Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 

Output:
64
1000

Explanation: Testcase 1: 32*2 = 64.
             Testcase 2: 100*10 = 1000.
*/

// Link --> https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

// Code:
#define mod 1000000007
long long  multiplyTwoLists (Node* first , Node* second)
{
    long long num1 = 0, num2 = 0;
    while(first || second)
    {
        if(first)
        {
            num1 = ((num1*10)%mod + (first->data)%mod)%mod;
            first = first->next;
        }
        if(second)
        {
            num2 = ((num2*10)%mod + second->data%mod)%mod;
            second = second->next;
        }
    }
 
    return (num1%mod * num2%mod)%mod;
}

