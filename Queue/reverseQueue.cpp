

//function Template for C++

//Function to reverse the queue.

void reverse(queue<int>& q) {
        
    if(q.empty()) {
        return ;
    }
    
    int element = q.front();
    q.pop();
    
    reverse(q);
    
    q.push(element);
    
}

queue<int> rev(queue<int> q)
{
    // add code here.
    reverse(q);
    
    return q;
    
}