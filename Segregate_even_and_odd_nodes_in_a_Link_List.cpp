/*
Problem Statement:
------------------
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. 
The order of appearance of numbers within each segregation should be same as that in the original list.

Example 1:
---------
Input: 
N = 7
Link List = 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear first and 2,4,6 are the even numbers that appear later.

Example 2:
---------
Input:
N = 4
Link List = 1 -> 3 -> 5 -> 7
Output: 1 3 5 7

Explaination: There is no even number. So ne need for modification.

Your Task: You do not need to read input or print anything. Your task is to complete the function divide() 
which takes N and head of Link List as input parameters and returns the head of modified link list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

// Code:
class Solution
{
public:
    Node* divide(int N, Node *head)
    {
        Node *ort, *ert, *temp1, *temp2;
        int c1 = 0, c2 = 0, x;
        
        while(head != NULL)
        {
            x = head->data;
            if(x%2)
            {
                if(c1)
                {
                    temp1->next = new Node(x);
                    temp1 = temp1->next;
                }
                else
                {
                    temp1 = new Node(x);
                    ort = temp1;
                }
                c1++;
            }
            else
            {
                if(c2)
                {
                    temp2->next = new Node(x);
                    temp2 = temp2->next;
                }
                else
                {
                    temp2 = new Node(x);
                    ert = temp2;
                    c2++;
                }
            }
            head = head->next;
        }
        while(ort != NULL)
        {
            if(c2)
            {
                temp2->next = new Node(ort->data);
                temp2 = temp2->next;
            }
            else
            {
                temp2 = new Node(ort->data);
                ert = temp2;
                c2++;
            }
            ort = ort->next;
        }
        return ert;
    }
};
