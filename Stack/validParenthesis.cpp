bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;

    for (int i = 0; i < expression.length(); i++) {
        if(st.empty()) {
            st.push(expression[i]);
            continue ;
        }
        if ((expression[i] == '}' && st.top() == '{') || 
                (expression[i] == ']' && st.top() == '[') || 
                (expression[i] == ')' && st.top() == '(') ) {
                    st.pop();
                }

        else
            st.push(expression[i]);
    }

    if(st.empty())
        return true;
    else
        return false;
}