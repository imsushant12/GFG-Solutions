/*
Problem Statement:
------------------
Given an array of integers, replace every element with the least greater element on its right side in the array. 
If there are no greater elements on the right side, replace it with -1.

Examples: 
---------
Input: [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]
*/

// Link --> https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

// Code:
#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &v) 
{
    int n = v.size()-1;
        int compare = v[n];
        for(int i=n-1 ; i>=0 ; i--)
        {
            int temp = v[i];
            v[i] = compare;
            compare = max(compare , temp);
        }
        v[n] = -1;
        return v;
}

int main()
{
    vector<int> v;
    int data;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>data;
        v.push_back(data);
    }

    cout<<"\nArray after modifications : ";
    v = replaceElements(v);
    for(int i=0 ; i<n ; i++)
        cout<<v[i]<<"  ";

    return 0;
}
