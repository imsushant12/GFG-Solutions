/*
Problem Statement:
------------------
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
----------
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
----------
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. 
(The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

// Link --> https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Code:
void sortedInsert(stack <int> &s , int ele)
{
    // If the top element is smaller than the value we are passing or 
    // the stack is empty then we can simpy push the value into the stack.
    if(s.empty() || ele > s.top())
        s.push(ele);
        
    // Else, we will pop the top element and then recursively call the 
    // sortedInsert function on the value, to get its correct position.
    // Finally, we will push the popped element into the stack as it is greatest.
    else
    {
        int temp = s.top();
        s.pop();
        sortedInsert(s , ele);
        s.push(temp);
    }
}

void SortedStack :: sort()
{
    if(!s.empty())
    {
        int ele = s.top();
        s.pop();
        sort();
        sortedInsert(s,ele);
    }
}
