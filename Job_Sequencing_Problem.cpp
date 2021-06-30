/*
Problem Statement:
------------------
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.
Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

Example 1:
---------
Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation: 2 jobs can be done with maximum profit of 60 (20+40).

Example 2:
----------
Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

Your Task : You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an Integer N and an array 
of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Code:
class Solution 
{
public:
    static bool comparison(Job a , Job b)
    {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr , arr+n , comparison);
          
        int total = arr[0].dead;
        for(int i=1 ; i<n ; i++)
            total = max(total , arr[i].dead);
        
        vector <int> v(total+1 , -1);
        int counter=0 , profit=0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=arr[i].dead ; j>0 ; j--)
            {
                if(v[j] == -1)
                {
                    profit += arr[i].profit;
                    counter++;
                    v[j] = i;
                    break;
                }
            }
        }
        v.clear();
        v.push_back(counter);
        v.push_back(profit);
        
        return v;
    } 
};
