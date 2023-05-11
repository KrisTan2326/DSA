#include <bits/stdc++.h> 
class Deque
{
private:
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        arr = new int[n];
        qfront = -1;
        rear = -1;
        this -> size = n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if((qfront == 0 && rear == size-1) || qfront == rear+1)
            return false;
        
        if(qfront == -1 && rear == -1) {
            qfront = 0;
            rear = 0;
            arr[qfront] = x;
            return true;
        }

        if(qfront == 0 && rear < size-1) {
            qfront = size-1;
            arr[qfront] = x;
            return true;
        }

        qfront-- ;
        arr[qfront] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if((qfront == 0 && rear == size-1) || qfront == rear+1)
            return false;
        
        if(qfront == -1 && rear == -1) {
            qfront = 0;
            rear = 0;
            arr[qfront] = x;
            return true;
        }

        rear = (rear+1)%size;
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return -1;

        //single element present
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return -1;

        //single element present
        if(qfront == rear) {
            int value = arr[qfront];
            arr[qfront] = -1;
            qfront = -1;
            rear = -1;
            return value;
        }

        if(rear == 0) {
            int value = arr[rear];
            arr[rear] = -1;
            rear = size-1;
            return value;
        }

        int value = arr[rear];
        arr[rear] = -1;
        rear--;
        return value;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return -1;

        return arr[qfront];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return -1;

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(qfront == -1 && rear == -1)
            return true;

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((qfront == 0 && rear == size-1) || qfront == rear+1)
            return true;

        return false;
    }
};