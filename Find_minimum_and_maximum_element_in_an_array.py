'''
Problem Statement:
-----------------

Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

Example 1:
---------
Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000

Example 2:
----------
Input:
N = 5
A[]  = {1, 345, 234, 21, 56789}
Output:
min = 1, max = 56789
'''

# Link ---> https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

# Code:

def getMinMax(a , n):
    ls = []
    min = a[0]
    max = a[0]
    for i in a:
        if(min > i):
            min = i;
        elif(max < i):
            max = i;
    ls.append(min)
    ls.append(max)
    return ls
    
