/*
Problem Statement:
-----------------
We will be given a node and our task is to delete that node from the circular linked list.

Examples: 
--------
Input : 2->5->7->8->10->(head node)
        data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
        data = 7
Output : 2->5->8->10->2(head node)
*/

// Link --> https://www.geeksforgeeks.org/deletion-circular-linked-list/

// Code:
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref , int data)
{
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;

    if(*head_ref != NULL)
    {
        Node* temp = *head_ref;

        while (temp->next != *head_ref)
            temp = temp->next;

        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

void printList(Node* head)
{
    Node* temp = head;

    if (head != NULL)
    {
        do
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        while (temp != head);
    }
    cout<<endl;
}

void deleteNode(Node** head , int key)
{
    if(*(head) == NULL)
        return;

    // only one node in the list
    else if((*head)->data == key && (*head)->next == (*head))
    {
        free (*head);
        (*head) == NULL;
        return;
    }

    // first node is the node to be deleted
    else if((*head)->data == key)
    {
        struct Node *temp = *head;

        while(temp->next != (*head)->next)
            temp = temp->next;

        struct Node *del = (*head);
        (*head) = (*head)->next;
        temp->next = (*head);
        free (del);

        // Or simply:
        // temp->next=(*head)->next;
        // free(*head);
        // *head = temp->next;

        return;
    }

    else
    {
        struct Node *temp = *head;
        while(temp->next->data != key)
            temp = temp->next;

        struct Node *del = temp->next;

        temp->next = del->next;

        free (del);
        return;
    }
}

int main()
{
    Node* head = NULL;

    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    cout<<" List Before Deletion : ";
    printList(head);

    deleteNode(&head , 7);

    cout<<"List After Deletion : ";
    printList(head);

    return 0;
}
