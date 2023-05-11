//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i = 0; i < n; i++) {
            bool check = true;
            for(int j = 0; j < n; j++) {
                if(i == j) 
                    continue;
                else {
                    if(M[i][j] == 1) {
                        check = false;
                        break ;                    
                    }
                }
            }
            
            if(check) {
                for(int j = 0; j < n; j++) {
                    if(i == j) 
                        continue;
                    else {
                        if(M[j][i] == 0) {
                            check = false;
                            break ;                    
                        }
                    }
                }
            }
            
            if(check) {
                return i;
                break ;
            }
            
        }
        
        return -1;
        
    }
};