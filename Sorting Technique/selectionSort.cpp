#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   

    for(int i=0;i<n-1;i++){
        
        int min=i;
        for(int j=i;j<n-1;j++){
            if(arr[j+1]<arr[min])
                min=j+1;
        }

        swap(arr[i],arr[min]);
    }

}