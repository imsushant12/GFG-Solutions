/*
Problem Statement:
-----------------
We are given n-platform and two main running railway track for both direction. Trains which needs to stop at your station must occupy one platform for their stoppage 
and the trains which need not to stop at your station will run away through either of main track without stopping. Now, each train has three value first arrival time, 
second departure time and third required platform number. We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station.

Examples:
--------
Input : n = 3, m = 6 
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
Output : Maximum Stopped Trains = 5
Explanation : If train no. 1 will left 
to go without stoppage then 2 and 6 can 
easily be accommodated on platform 1. 
And 3 and 4 on platform 2 and 5 on platform 3.

Input : n = 1, m = 3
Train no.|Arrival Time|Dept. Time | Platform No.
    1    | 10:00      |  10:30    |    1
    2    | 11:10      |  11:30    |    1
    3    | 12:00      |  12:20    |    1
           
Output : Maximum Stopped Trains = 3
Explanation : All three trains can be easily
stopped at platform 1.
*/

// Link --> https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

// Code:
#include <bits/stdc++.h>
using namespace std;

#define n 2 //number of platforms
#define m 5 //number of trains

int maxStop(int a[][3])
{
	// declaring trains for each platform and then
	// calculating maximum trains for each each platform.
	vector <pair <int, int>> trains[n + 1];

	for (int i = 0; i < m; i++)
	{
		int platform = a[i][2];
		// storing as departure-time, arrival-time
		trains[platform].push_back({a[i][1], a[i][0]});
	}

	// sorting the each vector as per departure time.
	for (int i = 0; i <= n; i++)
		sort(trains[i].begin(), trains[i].end());


	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		if (trains[i].size() == 0)
			continue;

		int x = 0;
		count++;			//because first train is always selected for each platform.

		for (int j = 1; j < trains[i].size(); j++)
		{
			// The important (ACTIVITY SELECTION STEP)
			if (trains[i][j].second >= trains[i][x].first)
			{
				x = j;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int trains[m][3] = {1000, 1030, 1,
						1010, 1020, 1,
						1025, 1040, 1,
						1130, 1145, 2,
						1130, 1140, 2};

	cout << "Maximum trains that can be stopped is : " << maxStop(trains);

	return 0;
}
