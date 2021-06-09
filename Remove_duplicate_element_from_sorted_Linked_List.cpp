/*
Problem Statement:
-----------------
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:
---------
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.

Example 2:
---------
Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list 2 ->2 ->2 ->2 ->2, 2 is the only element and is repeated 5 times.

Your Task: The task is to complete the function removeDuplicates() which should remove the duplicates from linked list and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#

// Code:
Node *removeDuplicates(Node *head)
{
    Node *newHead = head;
    
    while(newHead->next != NULL)
    {
        if(newHead->data == newHead->next->data)
        {
            newHead->next = newHead->next->next;
        }
        else
        {
            newHead = newHead->next;
        }
    }
    return head;
}
