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

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL)
        return NULL;
    
    unordered_map<int,bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        
        if(visited[curr -> data]) {
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
            curr = prev -> next;
        }
        
        else {
            visited[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
        
    }
    
    return head;
    
}