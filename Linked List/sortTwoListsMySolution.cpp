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
    if(second == NULL)
        return first;

    Node<int>* temp1 = first;
    Node<int>* temp2 = second;
    Node<int>* last = NULL;
    Node<int>* third = new Node<int>(-1);
    third -> data = -1;
    Node<int>* temp3 = third;

    while(temp1 != NULL && temp2 != NULL) {

        Node<int>* forward = NULL;
        if(temp1 -> data < temp2 -> data) {
            forward = temp1 -> next;
            temp1 -> next = NULL;
            temp3 -> next = temp1;
            temp3 = temp3 -> next;
            temp1 = forward;
        }

        else {
            forward = temp2 -> next;
            temp2 -> next = NULL;
            temp3 -> next = temp2;
            temp3 = temp3 -> next;
            temp2 = forward;
        }

    }

    if(temp1 != NULL) {
        temp3 -> next = temp1;
    }

    if(temp2 != NULL) {
        temp3 -> next = temp2;
    }

    third = third -> next;
    return third;
    
}
