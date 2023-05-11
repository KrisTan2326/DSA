// * * * * * * *  * * * * * * *
// * * * * *          * * * * *
// * * * *              * * * *
// * * *                  * * *
// * *                      * *
// *                          *
// *                          *
// * *                      * *
// * * *                  * * *
// * * * *              * * * *
// * * * * *          * * * * *
// * * * * * *      * * * * * *
// * * * * * * *  * * * * * * *

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cout << "* ";
        }
        
        for(int j = 0; j < 4*i; j++)
            cout << " ";
        
        for(int j = i; j < n; j++) {
            cout << " *";
        }
        
        cout << endl;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = n-i-1; j < n; j++) {
            cout << "* ";
        }
        
        for(int j = 0; j < 4*(n-i-1); j++)
            cout << " ";
        
        for(int j = n-i-1; j < n; j++) {
            cout << " *";
        }
        
        cout << endl;
    }

    return 0;
}