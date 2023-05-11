#include<iostream>
#include<stdbool.h>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int studentCount=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]+sum<=mid){
            sum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            else{
                sum=arr[i];
            }
        }
    }
    return true;
}

int bookAllocated(int arr[],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int s=0,e=sum,ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int arr[]={10,20,30,40};
    int ans=bookAllocated(arr,4,4);
    cout<<"The answer is "<<ans;

    return 0;
}