/*
Problem Statement:
------------------
Write a function that checks whether a given Linked List contains a loop. If the loop is present 
then it returns point to the first node of the loop. Else it returns NULL.

Example:
-------
Input: head = [3,2,0,-4].
Output: 2

As:
3 --> 2 --> 0 --> -4
      |            |
       ------------
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed). HEnce return 2.
*/

// Link --> https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

/*
void printList(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}
*/

Node* detectFirstLoopNode(Node* head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;

    while(fast != slow )
    {
        if(!fast || !slow)
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    // A loop for testing.
    head->next->next->next->next->next = head->next->next;

    Node* answer = detectFirstLoopNode(head);

    if(answer)
        cout<<"First loop node is : "<<answer->data<<endl;
    else
        cout<<"No loop is present!"<<endl;

    return 0;
}

