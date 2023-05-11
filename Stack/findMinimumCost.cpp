#include <bits/stdc++.h> 

int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2 != 0)
    return -1;

  stack<char> stack;

  int countOpen = 0;
  int countClose = 0;

  for(int i = 0; i < str.length(); i++) {

    char ch = str[i];
    char top;
    if(!stack.empty())
      top = stack.top();

    if (ch == '{')
      stack.push(ch);

    else {
      if (!stack.empty() && top == '{')
        stack.pop();
      else
        stack.push(ch);
    }
  }

  while(!stack.empty()) {
    if(stack.top() == '{')
      countOpen++ ;
    else  
      countClose++ ;
    stack.pop();
  }

  return (countOpen+1)/2 + (countClose+1)/2;

}