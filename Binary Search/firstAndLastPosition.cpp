#include <bits/stdc++.h> 

int firstOccurence(vector<int>& arr, int n, int k) {

    int firstOcc = -1;
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == k) {
            firstOcc = mid;
            end = mid-1;
        }

        else if(arr[mid] < k)
            start = mid+1;

        else
            end = mid-1;

        mid = start + (end-start)/2;

    }

    return firstOcc;

}

int lastOccurence(vector<int>& arr, int n, int k) {

    int lastOcc = -1;
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == k) {
            lastOcc = mid;
            start = mid+1;
        }

        else if(arr[mid] < k)
            start = mid+1;

        else
            end = mid-1;

        mid = start + (end-start)/2;

    }

    return lastOcc;
    
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int firstOcc = firstOccurence(arr, n, k);
    int lastOcc = lastOccurence(arr, n, k);

    pair<int,int> p;
    p.first = firstOcc;
    p.second = lastOcc;

    return p;

}