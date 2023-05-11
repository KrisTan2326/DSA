#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {

    int start = 0, end = n-1;
    int mid = start + (end - start)/2;

    while(start <= end) {

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            start = mid + 1;

        else
            end = mid - 1;

        mid = start + (end - start)/2;

    }

    return -1;

}

int main(){
    int arr[] = {1,5,7,9,10,15};
    int pos = binarySearch(arr, 6, 9);

    if(pos == -1)
        cout << "Element not present!!!";
    else
        cout << "Element is present at position " << pos+1;

    return 0;
}