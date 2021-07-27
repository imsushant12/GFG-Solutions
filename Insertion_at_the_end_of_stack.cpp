/*
Problem Statement:
------------------
Given a stack S and an integer N, the task is to insert N at the bottom of the stack.

Examples:
---------
Input: N = 7
S = 1 <- (Top)
      2
     3
     4
     5
Output: 1 2 3 4 5 7

Input: N = 17
S = 1 <- (Top)
     12
     34
     47
     15
Output: 1 12 34 47 15 17
*/

// Link --> https://www.geeksforgeeks.org/program-to-insert-an-element-at-the-bottom-of-a-stack/

// Code: 
#include <bits/stdc++.h>
using namespace std;

stack<int> insertUtil(stack<int> s, int N)
{
    if (s.empty())
        s.push(N);

    else
    {
        int X = s.top();
        s.pop();

        s = insertUtil(s, N);
        s.push(X);
    }
    return s;
}

void insertToBottom(stack<int> s, int N)
{
    s = insertUtil(s, N);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}



int main()
{
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);

    int N = 7;

    insertToBottom(S, N);

    return 0;
}
