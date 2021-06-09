/*
Problem Statement:
-----------------
Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.

Example:
--------
Input : DLL: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
X = 17
Output : 2

Explanation : The triplets are: (2, 6, 9) and (4, 5, 8).
*/

// Link --> https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

// Code:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next, *prev;
};

void insert(struct Node** head , int data)
{
    Node* temp = new Node;

    temp->data = data;
    temp->next = temp->prev = NULL;

    if((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

int countPairs(Node* first , Node* second , int x)
{
    int counter = 0;

    while(first != NULL && second != NULL && first != second)
    {
        int sum = first->data + second->data;

        if(sum == x)
        {
            counter++;
            first = first->next;
            second = second->prev;
        }

        else if(sum > x)
            second = second->prev;

        else
            first = first->next;
    }
    return counter;
}

int countTriplets(Node* head , int x)
{
    if(head == NULL)
        return 0;

    int counter = 0;

    Node *first , *last = head , *current = head;

    while(last->next != NULL)
        last = last->next;

    while(current != NULL)
    {
        int sum = x - current->data;
        // since list is sorted, we will check sum in rest list.
        first = current->next;

        counter += countPairs(first , last , sum);

        current = current->next;
    }
    return counter;
}

int main()
{
    Node* head = NULL;

    insert(&head , 9);
    insert(&head , 8);
    insert(&head , 6);
    insert(&head , 5);
    insert(&head , 4);
    insert(&head , 2);
    insert(&head , 1);

    int x = 17;

    cout<<"Count = "<<countTriplets(head , x);

    return 0;
}
