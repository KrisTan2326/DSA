#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeTwoSortedArray(vector<int> arr1, vector<int> arr2) {

    int m = arr1.size();
    int n = arr2.size();

    vector<int> res(n+m);

    int i = 0, j = 0, index = 0;
    while(i < m && j < n) {
        if(arr1[i] < arr2[j])
            res[index++] = arr1[i++];

        else   
            res[index++] = arr2[j++];
    }

    while(i < m)
        res[index++] = arr1[i++];

    while(j < n)
        res[index++] = arr2[j++];

    return res;
}

int main(){
    vector<int> arr1 = {1,2,5,7,9};
    vector<int> arr2 = {3,4,6};

    vector<int> res = mergeTwoSortedArray(arr1, arr2);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}