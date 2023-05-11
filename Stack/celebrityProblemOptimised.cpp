//User function template for C++

class Solution 
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> stack;
        
        for(int i = 0; i < n; i++)
            stack.push(i);
          
        while(stack.size() != 1) {
            
            int A = stack.top();
            stack.pop();
            int B = stack.top();
            stack.pop();
                
            if(M[A][B])
                stack.push(B);
            else
                stack.push(A);
            
        }
        
        int A = stack.top();
        bool check = true;
        for(int i = 0; i < n; i++) {
            if(i == A)
                continue;
            
            if(M[i][A] == 0) {
                 check = false;
                 break ;
            }
            
        }
        
        if(check) {
            for(int i = 0; i < n; i++) {
                if(i == A)
                    continue;
                
                if(M[A][i] == 1) {
                     check = false;
                     break ;
                }
                
            }
        }
        
        if(check)
            return A;
        else
            return -1;
        
    }
};
