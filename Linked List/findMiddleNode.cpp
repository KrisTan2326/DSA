#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

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

Node *findMiddle(Node *head) {
    // Write your code here
    int n = 1;

    Node* temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next;
        n++ ;
    }

    if(n%2 == 0) {
        int count = 1;
        temp = head;
        while(count < n/2 + 1) {
            temp = temp -> next;
            count++ ;
        }
    }

    else {
        int count = 1;
        temp = head;
        while(count <= n/2) {
            temp = temp -> next;
            count++ ;
        }
    }

    return temp;
}