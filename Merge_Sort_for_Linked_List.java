/*
Problem Statement:
-----------------
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:
----------
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.

Example 2:
----------
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given linked list , resultant will be 0->9->15.

Your Task: For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
*/

// Link --> https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

// Code:
class Solution
{
    static Node merge(Node head1 , Node head2)
    {
        Node merged = new Node(-1);
        Node temp = merged;
       
        while(head1 != null && head2 != null) 
        {
            if(head1.data < head2.data) 
            {
                temp.next = head1;
                head1 = head1.next;
            }
            else 
            {
                temp.next = head2;
                head2 = head2.next;
            }
            temp = temp.next;
        }

        while(head1 != null) 
        {
            temp.next = head1;
            head1 = head1.next;
            temp = temp.next;
        }
       
        while(head2 != null) 
        {
            temp.next = head2;
            head2 = head2.next;
            temp = temp.next;
        }
        return merged.next;
    }
    
    static Node split(Node head)
    {
        Node slow = head;
        Node fast = head.next;
        while(fast != null && fast.next != null) 
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    static Node mergeSort(Node head)
    {
        if(head.next == null)
            return head;
        
        Node mid = split(head);
        Node temp = mid.next;
        mid.next = null;
        Node head1 = mergeSort(head);
        Node head2 = mergeSort(temp);
        
        Node resultHead = merge(head1 , head2);
        
        return resultHead;
    }
}
