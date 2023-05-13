//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void checkQueue(queue<char> &q, int *count) {
            
            if(count[q.front()-'a'] == 1)
                return ;
                
            while(!q.empty() && count[q.front()-'a'] != 1) {
                q.pop();
            }
            
        }
    
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int count[26] = {0};
		    queue<char> q;
		    
		    string s = "";
		    
		    for(int i = 0; i < A.length(); i++) {
		        
		        char ch = A[i];
		        
		        count[ch-'a']++ ;
		        q.push(ch);
		            
		        checkQueue(q, count);
		            
		        if(q.empty())
		            s.push_back('#');
		        else {
		            s.push_back(q.front());
		        }

		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends