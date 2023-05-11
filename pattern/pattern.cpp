// 10
// *        *
//  *      *
//   *    *
//    *  *
//     **
//     **
//    *  *
//   *    *
//  *      *
// *        *

// 7
// *     *
//  *   *
//   * *
//    *
//   * *
//  *   *
// *     *

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = n-2;
    
    if(n%2 == 0) {
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < i; j++) {
                cout << " ";
            }
            cout << "*";
            for(int k = 0; k < count; k++) {
                cout << " ";
            }
            count = count - 2;
            cout << "*";
            cout << endl;
        }
        
        count = 0;
        for(int i = 0; i < n/2; i++) {
            for(int j = n/2-i-1; j > 0; j--) {
                cout << " ";
            }
            cout << "*";
            for(int k = 0; k < count; k++ ) {
                cout << " ";
            }
            count += 2;
            cout << "*";
            cout << endl;
        }
    }
    
    if(n%2 != 0) {
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < i; j++) {
                cout << " ";
            }
            cout << "*";
            for(int k = 0; k < count; k++) {
                cout << " ";
            }
            count = count - 2;
            cout << "*";
            cout << endl;
        }
        count = 1;
        
        for(int i = 0; i < n/2; i++)
            cout << " ";
        cout << "*" << endl;
        
        for(int i = 0; i < n/2; i++) {
            for(int j = n/2-i-1; j > 0; j--) {
                cout << " ";
            }
            cout << "*";
            for(int k = 0; k < count; k++ ) {
                cout << " ";
            }
            count += 2;
            cout << "*";
            cout << endl;
        }
    }
    
    return 0;
}