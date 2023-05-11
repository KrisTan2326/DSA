#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s = "krishna";

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    
    string ans = "";

    while(!st.empty()) {
        char word = st.top();
        ans.push_back(word);
        st.pop();
    }

    cout << ans;

    return 0;
}