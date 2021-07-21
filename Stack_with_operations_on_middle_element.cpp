/*
Problem Statement:
------------------
How to implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/

// Link --> https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// Code:
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node()
    {
        prev = next = NULL;
    }
};

class Stack : public Node
{
private:
    Node *head;
    Node *middle;
    int counter;

public:
    Stack()
    {
        head = middle = NULL;
        counter = 0;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    void push(int data)
    {
        counter++;
        Node *node = new Node();
        node->data = data;
        cout << data << " is pushed in." << endl;
        node->prev = NULL;
        node->next = head;

        if (head != NULL)
            head->prev = node;

        head = node;

        if (counter == 1)
            middle = node;
        else
        {
            if (!(counter & 1))
                middle = middle->prev;
        }
    }

    void pop()
    {
        if (counter == 0 || isEmpty())
            cout << "\nStack is empty." << endl;

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        counter--;

        // if counter is odd.
        if (counter & 1)
            middle = middle->next;

        cout << temp->data << " is popped out." << endl;

        free(temp);
    }

    void middleElement()
    {
        if (counter == 0)
            cout << "\nStack is empty." << endl;

        cout << "\nMiddle element is : " << middle->data << endl;
    }

    void display()
    {
        Node *temp;
        while (temp->next != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);
    s.push(66);
    s.push(77);

    s.middleElement();

    s.pop();
    s.pop();
    s.pop();

    s.middleElement();

    return 0;
}
