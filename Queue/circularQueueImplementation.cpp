#include <bits/stdc++.h> 
class CircularQueue{
    private:
    int *arr;
    int qfront;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        arr = new int[n];
        this -> size = n;
        qfront = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((qfront == 0 && rear == size-1) || qfront == rear+1)
            return false;
        
        if(qfront == -1 && rear == -1) {
            qfront = 0;
            rear = 0;
            arr[qfront] = value;
            return true;
        }

        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return -1;
            
        //only one element present
        if(qfront == rear) {
            int value = arr[qfront];
            arr[qfront] = -1;
            qfront = -1;
            rear = -1;
            return value;
        }

        int value = arr[qfront];
        arr[qfront] = -1;
        qfront = (qfront+1)%size;
        return value; 
    }
};