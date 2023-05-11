// /************************************************************

//     Following is the linked list node structure.
    
//     class Node 
//     {
//         public:
//         int data;
//         Node* next;

//         Node(int data) 
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };
    
// ************************************************************/

// Node * uniqueSortedList(Node * head) {
//     // Write your code here.
//     Node* curr = head;
//     Node* forward = NULL;
//     Node* temp = NULL;
//     int val;
    
//     while(curr != NULL) {
//         val = curr -> data;
//         temp = curr -> next;

//         while (temp != NULL && (temp->data) == (curr->data)) {
//           forward = temp->next;
//           temp->next = NULL;
//           delete temp;
//           temp = forward;
//         }

//         curr->next = temp;
//         curr = curr->next;
//     }

//     return head;
// }

/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/




Node * uniqueSortedList(Node * head) {
    // Write your code here.
    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {

        if ((curr -> next != NULL) && ((curr->data) == (curr->next->data))) {
            Node* forward = curr->next->next;
            temp = curr->next;
            temp->next = NULL;
            delete temp;
            curr -> next = forward;
        }

        else {
            curr = curr -> next;
        }
        
    }

    return head;
    
}