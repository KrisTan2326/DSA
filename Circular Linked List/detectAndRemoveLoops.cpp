/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {

        slow = slow -> next;
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
        }

        if(slow == fast)
            return slow;

    }

    return NULL;
}

Node* getStartingNode(Node* head) {

    if(head == NULL)
        return NULL;

    Node* intersectingNode = floydDetectLoop(head);

    if(intersectingNode == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersectingNode) {

        slow = slow -> next;
        intersectingNode = intersectingNode -> next;

    }

    return intersectingNode;

}

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head == NULL)
        return NULL;

    Node* startingNode = getStartingNode(head);

    if(startingNode == NULL)
        return head;

    Node* temp = startingNode;

    while(temp -> next != startingNode) {
        temp = temp -> next;
    }

    temp -> next = NULL;

    return head;

}