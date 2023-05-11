/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findMid(node* &head) {

    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}

node* merge(node* &left, node* &right) {

    if(left == NULL)
        return right;

    if(right == NULL)
        return left; 

    node* prev = left;
    node* curr = left -> next;
    node* temp = right;

    while(curr != NULL && temp != NULL) {

        node* forward = temp -> next;
        if((temp -> data >= prev -> data) && (temp -> data <= curr -> data)) {
            prev -> next = temp;
            temp -> next = curr;
            prev = prev -> next;
            temp = forward;
        }

        else {
            curr = curr -> next;
            prev= prev -> next;
        }

    }

    if(temp != NULL) 
        prev -> next = temp;

    return left;

}

node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL)
        return head;

    if(head -> next == NULL)
        return head;

    node* mid = findMid(head);

    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = NULL;
    if(left -> data < right -> data)
        result = merge(left, right);

    else
        result = merge(right, left);

    return result;

}
