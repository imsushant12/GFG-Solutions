/*
Problem Statement:
-----------------
Given n appointments, find all conflicting appointments. 

Examples:
---------
Input: appointments[] = { {1, 5} {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}}

Output: 
Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]
An appointment is conflicting if it conflicts with any of the previous appointments in the array.
*/

// Link --> https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int low, high;
};

void printConflicting(Interval appt[], int n , int start)
{
    int low = appt[start].low;
    int high = appt[start].high;

    for (int i = start+1 ; i<n ; i++)
    {
        if (appt[i].low >= low and appt[i].low <= high)
        {
            cout << "{" << low << " , " << high << "}"
                 << " has conflict with : {" << appt[i].low << " , " << appt[i].high << "}" << endl;
        }
    }
}

int main()
{
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};

    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals: " << endl;
    for(int i=0 ; i<n ; i++)
    {
        printConflicting(appt, n, i);
        cout<<endl;
    }

    return 0;
}
