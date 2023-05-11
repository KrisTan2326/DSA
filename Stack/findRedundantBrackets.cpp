#include <bits/stdc++.h> 

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> stack;

    for(int i = 0; i < s.length(); i++) {
    
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
            stack.push(s[i]);

        else {

            //lowercase ya )
            if(s[i] == ')') {
                bool isRedundant = true;
            
                while(stack.top() != '(') {
                    char top = stack.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                        isRedundant = false;

                    stack.pop();
                }

                if(isRedundant)
                    return true;
            
                stack.pop();

            }

        }

    }

    return false;    

}
