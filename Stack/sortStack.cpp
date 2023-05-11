#include <bits/stdc++.h> 

void insertAtPosition(stack<int> &stack, int element) {

    if(stack.empty() || element > stack.top()) {
        stack.push(element);
        return ;
    }

    int top = stack.top();
    stack.pop();

    insertAtPosition(stack, element);

    stack.push(top);

}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return ;

	int element = stack.top();
	stack.pop();

	sortStack(stack);

	insertAtPosition(stack, element);

}