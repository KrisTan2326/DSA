#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* merge(Node* first, Node* second) {

	if(first == NULL)
		return second;
	
	if(second == NULL)
		return first;

	Node* prev = first;
	Node* curr = first -> child;
	Node* temp = second;

	while(curr != NULL && temp != NULL) {

		Node* forward = temp -> child;
		if((temp -> data >= prev -> data) && (temp -> data <= curr -> data)) {
			prev -> child = temp;
			temp -> child = curr;
			prev = prev -> child;
			temp = forward;
		}

		else {
			curr = curr -> child;
			prev = prev -> child;
		}

	}

	if(temp != NULL)
		prev -> child = temp;

	return first;

}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL)
		return head;
	
	Node* first = head;
	Node* second = head -> next;
	first -> next = NULL;
	second = flattenLinkedList(second);

	Node* result = merge(first, second);

	return result;

}
