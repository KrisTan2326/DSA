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

Node *firstNode(Node *head)
{
	//    Write your code here.

	if(head == NULL)
		return NULL;

	Node* temp = head;
	map<Node* , bool> visited;

	visited[temp] = true;

	while(temp != NULL) {

		temp = temp -> next;

		if(visited[temp]) {
			return temp;
		}

		visited[temp] = true;

	}

	return NULL;
}

node* getStartingNode(node* head) {

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast != NULL) {

        

    }

}