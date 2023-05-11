#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,5,4};
    int max1 = INT32_MIN ;
    max1 = max(max1, arr[3]);

    cout << max1;

    return 0;
}