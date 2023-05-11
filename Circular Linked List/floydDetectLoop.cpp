node* floydDetectLoop(node* head) {

    if(head == NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

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

node* getStartingNode(node* head) {

    if(head == NULL)
        return NULL;

    node* intersectingNode = floydDetectLoop(head);
    node* slow = head;

    while(slow != intersectingNode) {

        slow = slow -> next;
        intersectingNode = intersectingNode -> next;

    }

    return intersectingNode;

}

void removeLoop(node* head) {

    if(head == NULL)
        return ;

    node* startingNode = getStartingNode(head);
    node* temp = startingNode;

    while(temp -> next != startingNode) {
        temp = temp -> next;
    }

    temp -> next = NULL;

}