/*
Problem Statement:
-----------------
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:
---------
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
             
Example 2:
--------
Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() 
that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).
*/

// Link --> https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

// Code:
vector <int> result;
vector<int> find(int a[] , int n , int x)
{
    // declared a global vector so clearing it out after each function call
    result.clear();
    
    // flag1 will take care of last occurence
    // flag2 will take care of case when target is not found
    bool flag1 = true, flag2 = true;
    int temp;
    
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == x && a[i-1] != x)
        {
            result.push_back(i);
            temp = i;
            flag2 = false;
        }
        else if(a[i] == x && a[i+1] != x)
        {
            result.push_back(i);
            flag1 = false;
            break;
        }
    }
    
    // when the element has occured only one time
    if(flag1 == true && flag2 == false)
        result.push_back(temp);
    
    // if element is not found
    else if(flag2 == true && flag1 == true)
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    return result;
}
