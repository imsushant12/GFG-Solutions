/*
Problem Statement:
------------------
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:
---------
Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the resultant linked list is 4->2->2->1->8->7->6->5.

Example 2:
---------
Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed first and then elements 4,5 are reversed. Hence, the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return 
the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
*/

// Link --> https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// Code:
class Solution
{
    public:
    
    node *reverse(node *head , int k)
    { 
        node* current = head;
    	node* next = NULL;
    	node* prev = NULL;
    	int count = 0; 
    	
    	while(current != NULL && count < k)
    	{
    		next = current->next;            
    		current->next = prev;             
    		prev = current;                   
    		current = next;                   
    		count++;
    	}
    	
    	if(next != NULL)      
        	head->next = reverse(next, k);  
        
    	return prev;      
    }
};
