#include <bits/stdc++.h> 

bool isPossible(vector<int> &rank, int m, int mid) {

    int dishCount = 0;

    for(int i = 0; i < rank.size(); i++) {

        int count = 1, time = 0;
        while(time <= mid) {
            time += rank[i]*count;
            count++ ;
            dishCount++ ;
        }
        dishCount-- ;

    }

    if(dishCount >= m)
            return true;
    else
        return false;

}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int cooksCount = rank.size();
    int ans;

    int start = 0;
    int end = rank[cooksCount-1]*m*(m+1)/2;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(isPossible(rank, m, mid)) {
            ans = mid;
            end = mid - 1;
        }

        else 
            start = mid + 1;

        mid = start + (end-start)/2;

    }

    return ans;

}
