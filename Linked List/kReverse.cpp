#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {

    if(head == NULL)
        return NULL;

    // Write your code here.
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    int count = 1;
    while(count <= k && curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++ ;
    }

    if(forward != NULL)
        head -> next = kReverse(forward, k);

    return prev;

    
    // if(head == NULL) {
    //     return NULL;
    // }
    
    // //step1: reverse first k nodes
    // Node* next = NULL;
    // Node* curr = head;
    // Node* prev = NULL;
    // int count= 1;
    
    // while( curr != NULL && count <= k ) {
    //     next = curr -> next;
    //     curr -> next = prev;
    //     prev = curr;
    //     curr = next;
    //     count++;
    // }
    
    // //step2: Recursion dekhlega aage ka 
    // if(next != NULL) {
    //     head -> next = kReverse(next,k);
    // }
    
    // //step3: return head of reversed list
    // return prev;

}