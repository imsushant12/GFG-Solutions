/*
Problem Statement:
------------------
Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)
*/

// Link --> 

//  Code:
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, element);
    s.push(top);
}

void reverse(stack<int> &s)
{
    if (s.empty())
        return;

    int current = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, current);
}

void printStack(stack<int> s)
{
    stack<int> temp;
    temp = s;
    while (!temp.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse(s);
    cout << "\nReversed Stack is : ";
    printStack(s);

    return 0;
}
