/*
Problem Statement:
-----------------
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:
---------
Input:
LinkedList: 4->5->6
Output: 457 

Example 2:
---------
Input:
LinkedList: 1->2->3
Output: 124 

Your Task: Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. 
The driver code prints the number.

Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

// Link --> https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

// Code:
class Solution
{
    public:
    
    Node* reverse(Node *head) 
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;
            
        while(current != NULL) 
        { 
            next = current->next;     
            current->next = prev;  
            prev = current;         
            current = next;       
        }
        return prev; 
    } 
    
    Node* addOne(Node *head) 
    {
        head = reverse(head);           
        Node* current = head;
        int carry = 1;
            
        while(carry)
        {
            current->data += 1;         
                
            if(current->data < 10) 
                return reverse(head);
                
            else 
                current->data = 0;
                
            if(current->next == NULL) 
                break;
                
            else 
                current = current->next;
        }
        current->next = new Node(1); 
        return reverse(head);
    }
};
