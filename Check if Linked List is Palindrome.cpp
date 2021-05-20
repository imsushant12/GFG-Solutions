/*
Problem Statement:
-----------------
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
---------
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is 1 2 1 , which is a palindrome and Hence, the output is 1.

Example 2:
---------
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list is 1 2 3 4 , which is not a palindrome and Hence, the output is 0.

Your Task: The task is to complete the function isPalindrome() which takes head as reference as the only parameter and 
returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/

// Link -> https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

// Code:
class Solution{
  public:
    //Function to reverse the linked list.
    Node* reverseList(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
    }
  
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        bool answer = true;
        int count = 0;
        Node* ptr;
        
        for(ptr=head ; ptr ; ptr=ptr->next )
            count++;
        
        if(count < 2) 
            return 1;
        
        ptr = head;
        int mid = (count - 1) / 2;
        
        while(mid--)
            ptr = ptr->next;

        Node* head2 = ptr->next;
        ptr->next = NULL;     
        
        // Reversing the half list.
        head2 = reverseList(head2);
        
        Node *temp1 = head;
        Node *temp2 = head2;
        
        for( ; temp1 && temp2 ; temp1 = temp1->next , temp2 = temp2->next)
        {
            if(temp1->data != temp2->data)
            {
                answer = false;
                break;
            }
        }
        
        // Re-reversing the half list to original list.
        head2 = reverseList(head2);
        ptr->next = head2;
        
        return answer;
    }
};
