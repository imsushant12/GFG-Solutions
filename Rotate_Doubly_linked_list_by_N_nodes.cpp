/*
Problem Statement:
------------------
Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list. 
 
Examples: 
---------
Input : a  b  c  d  e   (N = 2)
Output : c  d  e  a  b 

Input : a  b  c  d  e  f  g  h   (N = 4)
Output : e  f  g  h  a  b  c  d 
*/

// Link --> https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void push(struct Node** head , int new_data)
{
    Node* new_node = new Node;

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head);

    if((*head) != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void printList(struct Node* node)
{
    while(node->next != NULL)
    {
        cout<<node->data<<"  "<<"<-->"<<"  ";
        node = node->next;
    }
    cout<<node->data;
}

void rotateDLL(struct Node** head , int n)
{
    if(n == 0)
        return;

    Node* current = *head;

    int counter = 1;
    while(counter < n && current != NULL)
    {
        current = current->next;
        counter++;
    }
    // current will now point to one node before the new head
    if(current == NULL)
        return;

    Node* lastNode = current;


    while(current->next != NULL)
        current = current->next;

    current->next = *head;

    (*head)->prev = current;
    (*head) = lastNode->next;
    (*head)->prev = NULL;

    lastNode->next = NULL;
}

int main(void)
{
    Node* head = NULL;

    push(&head , 10);
    push(&head , 20);
    push(&head , 30);
    push(&head , 40);
    push(&head , 50);

    int n = 4;

    cout<<"Linked list before rotation : ";
    printList(head);

    rotateDLL(&head , n);

    cout<<"\n\nLinked list after rotation : ";
    printList(head);

    return 0;
}
