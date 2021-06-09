/*
Problem Statement:
------------------
Write a function that moves the last element to the front in a given Singly Linked List. 
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
*/

// Link --> https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insert(int key)
{
    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = head;
    head = newNode;
}

void display()
{
    Node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
}

void moveToFront()
{
    Node *temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // getting the last node and making second last node point to NULL.
    Node *lastNode = temp->next;
    temp->next = NULL;

    // getting the first node list.
    Node *firstNode = head;

    // moving the last node in front.
    lastNode->next = head;
    head = lastNode;
}

int main()
{
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);

    cout<<"The linked list is: ";
    display();

    moveToFront();

    cout<<"\nThe updated linked list is: ";
    display();

    return 0;
}

