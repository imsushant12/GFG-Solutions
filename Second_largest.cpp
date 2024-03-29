/*
Problem Statement:
------------------
Given an array Arr of size N, print second largest distinct element from an array.

Example 1:
---------
Input: 
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Example 2:
----------
Input: 
N = 3
Arr[] = {10, 5, 10}
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Your Task: You don't need to read input or print anything. Your task is to complete the function print2largest() which takes the array of integers arr 
and n as parameters and returns an integer denoting the answer. If 2nd largest element doesn't exist then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arri ≤ 105
*/

// Link --> https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Code:
class Solution{
public:	
	// Function returns the second largest elements
	int print2largest(int arr[], int n) {
	int i, first, second;
 
    	/* There should be atleast two elements */
    	if (n < 2) {
        	return -1;
    	}
 
    	first = second = INT_MIN;
    	for (i = 0; i < n; i++) {
        	/* If current element is greater than first
           	then update both first and second */
        	if (arr[i] > first) {
            		second = first;
            		first = arr[i];
       		}
 
        	/* If arr[i] is in between first and
           	second then update second  */
        	else if (arr[i] > second && arr[i] != first)
            		second = arr[i];
    	}
    	if (second == INT_MIN)
		return -1;
    	else
        	return second;
	}
};

