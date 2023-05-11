/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  private:
    Node* middleNode(Node* &head) {
        
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast) {
            
            fast = fast -> next;
            
            if(fast != NULL) {
               fast = fast -> next; 
               slow = slow -> next;
            }
            
        }
        
        return slow;
        
    }
    
    Node* reverse(Node* &curr) {
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
  public: 
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL || head -> next == NULL)
            return true;
            
        Node* mid = middleNode(head);
        
        mid -> next = reverse(mid -> next);
        
        Node* secondHalf = mid -> next;
        bool flag = 1;
        
        while(secondHalf != NULL) {
            
            if(secondHalf -> data != head -> data) {
                flag = 0;
                break ;  
            }
                
            secondHalf = secondHalf -> next;
            head = head -> next;
            
        }
        
        return flag;
            
    }
};
