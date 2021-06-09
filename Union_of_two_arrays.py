""""
Problem Statement:
-----------------
Given two arrays a[] and b[] of size n and n respectively. The task is to find union between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, 
then only one occurrence of element should be printed in union.
Example 1:
--------
Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
Explanation: 1, 2, 3, 4 and 5 are the elements which comes in the union set of both arrays. So count is 5.

Example 2:
---------
Input:
6 2 
85 25 1 32 54 6
85 2 
Output: 
7
Explanation: 85, 25, 1, 32, 54, 6, and 2 are the elements which comes in the union set of both arrays. So count is 7.

Your Task: Complete doUnion funciton that takes a, n, b, m as parameters and returns the count of union elements of the two arrays.The printing is done by the driver code.

Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] < 105
Expected Time Complexity : O((n+m)log(n+m))
Expected Auxilliary Space : O(n+m)
"""

# Link --> https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

# Code:
class Solution:    
    #Function to return the count of number of elements in union of two arrays.
    def doUnion(self,a,n,b,m):
        # using a set to contain unique items
        temp = a[0]
        thisset = {temp}
        
        # adding items from list to the set
        thisset.update(b)    
        thisset.update(a)
        
        count = 0
        for i in thisset:
            count = count+1
            
        return count
