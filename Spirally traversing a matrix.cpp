/*
Problem Statement:
-----------------
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:
---------
Input:
r = 4 , c = 4
matrix[][] = {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12},
             {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Example 2:
---------
Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, 
r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c)

Constraints:
1 <= r , c <= 100
0 <= matrix(i) <= 100
*/

// Link --> https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

// Code:
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector <int> spirallyTraverse(vector <vector <int>> matrix , int r , int c) 
    {
        vector <int> result;
        
        int i=0 , k=0 , l=0;
        while(k<r && l<c) 
        {
            //row is fixed(first) and column is increasing
            for(i=l ; i<c ; i++) 
                result.push_back(matrix[k][i]);
            k++;
            
            //row is increasing and the column is fixed(last)
            for(i=k ; i<r ; i++)
                result.push_back(matrix[i][c-1]);
            c--;

            if(k < r) 
            {
                //last row is fixed and column is decreasing
                for(i=c-1 ; i>=l ; i--)
                    result.push_back(matrix[r-1][i]);
                r--;
            }
 
            if(l < c) 
            {
                //first column is fixed and row is decreasing
                for(i=r-1 ; i>=k ; i--)
                    result.push_back(matrix[i][l]);
                l++;
            }
        }
        return result;
    }
};
//comments are as per the first iterations
