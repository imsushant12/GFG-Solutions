#include <bits/stdc++.h>
using namespace std;

void Ksmallest(int a[] , int k , int n)
{
    priority_queue <int> maxHeap;

    for(int i=0 ; i<n ; i++)
        maxHeap.push(a[i]);

    for(int i=0 ; i<(n-k) ; i++)
        maxHeap.pop();

    cout<<maxHeap.top();
}

void Klargest(int a[] , int k , int n)
{
    priority_queue <int> maxHeap;

    for(int i=0 ; i<n ; i++)
        maxHeap.push(a[i]);

    for(int i=0 ; i<k-1 ; i++)
        maxHeap.pop();

    cout<<maxHeap.top();
}

int main()
{
    int a[] = {11 , 3 , 2 , 1 , 15 , 5 , 4 , 47 , 88 , 96 , 50 , 45};
    int n = sizeof(a) / sizeof(a[0]);

    //lets assume k is 3
    int k = 3;

    cout<<"Kth smallest element is : ";
    Ksmallest(a , k , n);

    cout<<"\nKth largest element is : ";
    Klargest(a , k , n);
    return 0;
}


