#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    else if(second == NULL)
        return first;
        
    
    Node<int>* prev = NULL;
    Node<int>* curr = first;

    Node<int>* temp = second;
    
    Node<int>* forward = NULL;
    if(prev == NULL && temp->data <= curr -> data) {
        forward = temp -> next;
        prev = temp;
        first = prev;
        prev -> next = curr;
        temp = forward;
    }
        
    else {
        prev = first;
        curr = curr -> next;
    }
    
    while(curr != NULL && temp != NULL) {
        
        if(temp->data >= prev->data && temp->data <= curr -> data) {
            forward = temp -> next;
            prev -> next = temp;
            temp -> next = curr;
            prev = temp;
            temp = forward;
        }
        
        else {
            prev = prev -> next;
            curr = curr -> next;
        }
        
    }

    //if only one element is present then this case will handle
    if(temp != NULL) {
        prev -> next = temp;
    }

    return first;
    
}
