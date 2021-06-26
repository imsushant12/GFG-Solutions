/*
Problem Statement:
-----------------
Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.

Examples:
--------
Input : DLL : 10 <-> 8 <-> 4 <-> 2 
Output: DLL : 8 <-> 10 <-> 2 <-> 4
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

Node *getNode(int data)
{
    Node *new_node = new Node;

    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push(Node **head_ref, Node *new_node)
{
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *revListInGroupOfGivenSize(Node *head, int k)
{
    int counter = 0;
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while(counter != k and current != NULL)
    {
        next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
        counter++;
    }
    if(next != NULL)      
        	head->next = revListInGroupOfGivenSize(next, k);

    return prev;
}

int main()
{
    Node *head = NULL;
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    cout << "Original list is :  ";
    printList(head);

    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list is : ";
    printList(head);

    return 0;
}
