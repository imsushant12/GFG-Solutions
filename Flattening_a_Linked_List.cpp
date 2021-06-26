/*
Problem Statement:
------------------
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:
---------
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Explanation: The resultant linked lists has every node in a single level.
(Note: | represents the bottom pointer.)
 
Example 2:
---------
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50

Explanation: The resultant linked lists has every node in a single level.

Your Task: You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter 
and returns the head of flattened link list.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Code:
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->data <= b->data) 
    {
        result = a;
        result->bottom = SortedMerge(a->bottom, b);
    }
    else 
    {
        result = b;
        result->bottom = SortedMerge(a, b->bottom);
    }
    return (result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->bottom;
 
    while (fast != NULL) 
    {
        fast = fast->bottom;
        if (fast != NULL) 
        {
            slow = slow->bottom;
            fast = fast->bottom;
        }
    }

    *frontRef = source;
    *backRef = slow->bottom;
    slow->bottom = NULL;
}

void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->bottom == NULL)) 
        return;

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);
 
    *headRef = SortedMerge(a, b);
}

Node* bottomOrder(Node *root)
{
    Node *current = root;
    Node *head = root;
    Node *next = current->next;
    
    while(current->bottom != NULL)
        current = current->bottom;
        
    if(next != NULL)
        current->bottom = bottomOrder(next);    
    return head;
}

Node *flatten(Node *root)
{
    Node *temp = bottomOrder(root);
    MergeSort(&temp);
    
    return temp;
}
