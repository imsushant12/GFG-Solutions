/*
Problem Statement:
------------------
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. 
The new list should be made with its own memory — the original lists should not be changed.

Example 1:
----------
Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6

Explanation: For the given first two linked list, 2, 4 and 6 are the elements in the intersection.

Example 2:
---------
Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40

Your Task: The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements 
in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.
*/

// Link --> https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

// Code:
Node* findIntersection(Node* head1, Node* head2)
{
    Node *h = head1;
    Node *head = NULL , *tail = NULL;
    
    unordered_set <int> us;
    while(h != NULL)
    {
        us.insert(h->data);
        h = h->next;
    }
    h = head2;
    while(h != NULL)
    {
        if(us.find(h->data) != us.end())
        {
            if(head == NULL )
                head = tail = new Node(h->data);
            else
            {
                tail->next = new Node(h->data);
                tail = tail->next;
            }
            us.erase(h->data);
        }
        h = h->next;
    }
    return head;
}
