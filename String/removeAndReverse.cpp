#include<iostream>
#include<string.h>

using namespace std;

//str.erase(str.begin() + 4);
void reverse(string& S) {
    int s = 0, e = S.length()-1;
    while(s <= e) {
        swap(S[s++], S[e--]);
    }
    
}

string removeReverse(string& S) {
    // code here
    int index;
    
    for(int i = 0; i < S.length(); ) {
        int count = 1;
        for(int j = i+1; j < S.length(); j++) {
            if(S[i] == S[j])
                count++ ;
                
            if(count == 2) {
                index = i;
                break ;
            }
            
        }
        if(count == 2) {
            S.erase(S.begin() + index);
            reverse(S);
            i = 0;
        }

        else
            i++ ;
                
    }
    
    return S;
      
}

int main() {
    string s = "aabraakaadaabraa";

    string newString = removeReverse(s);

    cout << newString;

    return 0;
}
