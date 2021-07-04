/*
Problem Statement:
-----------------
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. 
The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 
---------
Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
Output : 6 7 1 
*/

// Link --> https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

// Code:
#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int pos;
};

bool comparator(Meeting m1, Meeting m2)
{
    return (m1.end < m2.end);
}

void maxMeeting(int s[], int f[], int n)
{
    vector<int> v;
    Meeting m[n];

    for (int i = 0; i < n; i++)
    {
        m[i].start = s[i];
        m[i].end = f[i];
        m[i].pos = i + 1;
    }

    int count = 0;

    // sorting the meetings as per their finish time.
    sort(m, m + n, comparator);

    // initially first meeting is always selected.
    v.push_back(m[0].pos);

    int current_ending_time = m[0].end;
    for (int i = 1; i < n; i++)
    {
        if (m[i].start > current_ending_time)
        {
            current_ending_time = m[i].end;
            count++;
            v.push_back(m[i].pos);
        }
    }

    cout << "Scheduled meetings are:";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
}

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(s) / sizeof(s[0]);

    maxMeeting(s, f, n);

    return 0;
}
