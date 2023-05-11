#include <bits/stdc++.h> 

void insertionSort(int n, vector<int> &arr){ 

    for(int i=1;i<n;i++){
        
        int j=i;
        while(arr[j]<arr[j-1]){
            int elem=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=elem;
            j--;
        }

    }
}