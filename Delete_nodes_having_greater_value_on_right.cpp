/*
Problem Stateement:
-------------------
Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

Example 1:
---------
Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on their next node. So, after deleting them, the linked list would like be 15, 11, 6, 3.

Example 2:
---------
Input:
LinkedList = 10->20->30->40->50->60
Output: 60

Your Task: The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. 
The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

// Code:
class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;
    }
    
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *current = head;
        
        int max = head->data;
        Node *prev = head;
        head = head->next;
        while(head != NULL)
        {
            if(head->data >= max)
            {
                max = head->data;
                prev = head;
                head = head->next;
            }
            else
            {
                prev->next = head->next;
                head = prev->next;
            }
        }
        
        head = reverse(current);
        
        return head;
    }
    
};
