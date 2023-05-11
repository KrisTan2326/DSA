/********************************
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

********************************/

void insertAtTail(Node* &num, Node* &tail, Node* &temp) {
    if(num == NULL) {
        num = temp;
        temp -> next = NULL;
        tail = temp;
        return ;
    }
    
    tail -> next = temp;
    tail = temp;
    temp -> next = NULL;
}

Node* Merge(Node* zero, Node* one, Node* two) {
    
    Node* temp = zero;
    
    if(temp == NULL)
        temp = one;
    else {
        while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
        }
        temp->next = one;
    }

    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    
    temp -> next = two;
    
    if(zero != NULL)
        return zero;
    else if(one != NULL)
        return one;
    else
        return two;
    
}

Node* sortList(Node *head)
{
    // Write your code here.

    Node* zero = NULL;
    Node* one = NULL;
    Node* two = NULL;

    Node* tailZero = NULL;
    Node* tailOne = NULL;
    Node* tailTwo = NULL;
    
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
      
        forward = curr -> next;
        if(curr -> data == 0) {
            insertAtTail(zero, tailZero, curr);
            curr = forward;
        }
        
        else if(curr -> data == 1) {
            insertAtTail(one, tailOne, curr);
            curr = forward;
        }

        else{
            insertAtTail(two, tailTwo, curr);
            curr = forward;
        }
        
    }

    head = Merge(zero, one, two);

    return head;
    
}
