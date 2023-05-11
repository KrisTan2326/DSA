#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
    private:
    int mini = INT_MAX;
    stack<int> s;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()) {
            s.push(data);
            mini = data;
            return ;
        }

        if(data < mini) {
            int val = 2 * data - mini;
            s.push(val);
            mini = min(data, mini);
        }

        else    
            s.push(data);
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
            return -1;

        if(s.top() > mini) {
            int val = s.top();
            s.pop();
            return val;
        }

        else {
            int val = 2 * mini - s.top();
            int value = mini;
            mini = val;
            s.pop();
            return value;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty())
            return -1;

        if(s.top() < mini)
            return mini;
        else
            return s.top();

    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
            return -1;

        return mini;
    }  
};