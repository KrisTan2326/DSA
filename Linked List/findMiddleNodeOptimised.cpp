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
    Node* pro = head -> next;
    Node* noob = head;

    if(head -> next == NULL)
        return head;

    if(head -> next -> next == NULL)
        return head -> next;

    while(pro) {
        pro = pro -> next;

        if(pro != NULL)
            pro = pro -> next;
            
        noob = noob -> next;
    }

    return noob;
}