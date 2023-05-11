class Solution
{
    private:
    void insertAtTail(Node* &clone, Node* &cloneNode, Node* &temp) {
        if(clone == NULL) {
            clone = temp;
            cloneNode = temp;
            return ;
        }
        
        cloneNode -> next = temp;
        cloneNode = cloneNode -> next; 
    }
    
    
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* originalNode = head;
        
        Node* clone = NULL;
        Node* cloneNode = NULL;
        
        while(originalNode != NULL) {
            
            Node* temp = new Node(originalNode -> data);
            
            insertAtTail(clone, cloneNode, temp);
            
            originalNode = originalNode -> next;

        }
        
        originalNode = head;
        cloneNode = clone;

        while(originalNode != NULL) {
            
            Node* forward = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = forward;
            
            forward = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = forward;
            
        }       
        
        originalNode = head;
        cloneNode = clone;
        while(originalNode != NULL) {
            
            if(originalNode -> arb != NULL)
                cloneNode -> arb = originalNode -> arb -> next;
            originalNode = originalNode -> next -> next;
            
            cloneNode = cloneNode -> next;
            if(cloneNode != NULL)
                cloneNode = cloneNode -> next;
            
        }
        
        originalNode = head;
        cloneNode = clone;
        while(originalNode != NULL ) {
            
            originalNode -> next = cloneNode -> next;
            if(originalNode != NULL)
                originalNode = originalNode -> next;
            
            if(cloneNode -> next != NULL)
                cloneNode -> next = originalNode -> next;
                
            else
                cloneNode = NULL;
                
            if(cloneNode != NULL)
                cloneNode = cloneNode -> next;
            
        }
        
        
        return clone;
        
    }

};