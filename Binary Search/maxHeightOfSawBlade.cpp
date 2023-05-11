#include<iostream>
using namespace std;

int isPossible(int heights[],int n,int m,int mid){
    int max=0;
    for(int i=0;i<n;i++){
        if(heights[i]-mid>=0){
            max+=heights[i]-mid;
            

            if(max>=m){
                return true;
            }
        }
    }
    return false;
}

int maxHeightOfSawBlade(int heights[],int n,int m){
    int s=heights[0],e=heights[n-1];
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(heights,n,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int heights[]={4, 42, 40, 26, 46};
    int ans=maxHeightOfSawBlade(heights,5,20);
    cout<<"Answer is "<<ans;
    //4 42 40 26 46

    return 0;
}