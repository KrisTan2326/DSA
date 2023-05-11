class Solution
{
    private:
    void insertAndMap(Node* &clone, Node* &cloneNode, Node* &originalNode, Node* &temp, map<Node*,Node*> &mapping) {
        
        if(clone == NULL) {
            clone = temp;
            cloneNode = temp;
            mapping[originalNode] = clone;
            return ;
        }
        
        cloneNode -> next = temp;
        cloneNode = temp;
        mapping[originalNode] = cloneNode;
        
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        map<Node*,Node*> mapping;
        
        Node* originalNode = head;
        Node* clone = NULL;
        Node* cloneNode = NULL;
        Node* tail = NULL;
        
        while(originalNode != NULL) {
            
            Node* temp = new Node(originalNode -> data);
            
            insertAndMap(clone, cloneNode, originalNode, temp, mapping);
            
            originalNode = originalNode -> next;
        }
        
        cloneNode = clone;
        originalNode = head;
        while(cloneNode != NULL) {
            
            cloneNode -> arb = mapping[originalNode -> arb];
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
            
        }
        
        return clone;
        
    }

};